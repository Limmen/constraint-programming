//
// life.cpp
// Created by Kim Hammar & Mallu Goswami on 2017-05-01.
//

#include <gecode/driver.hh>
#include <gecode/int.hh>
#include <gecode/minimodel.hh>

using namespace Gecode;

class Life : public Script {

public:

    const int n;
    BoolVarArray cells;

    Life(const SizeOptions &opt) :
            Script(opt),
            n(opt.size()),
            cells(*this, (n + 4) * (n + 4), 0, 1) {
        Matrix <BoolVarArray> cellsMatrix(cells, n + 4, n + 4);

        /**
         * Ensure pattern does not spread. Constraints on the border
         */
        rel(*this, sum(cellsMatrix.row(n + 2)) == 0);
        rel(*this, sum(cellsMatrix.row(n + 3)) == 0);
        rel(*this, sum(cellsMatrix.row(0)) == 0);
        rel(*this, sum(cellsMatrix.row(1)) == 0);
        rel(*this, sum(cellsMatrix.col(n + 2)) == 0);
        rel(*this, sum(cellsMatrix.col(n + 3)) == 0);
        rel(*this, sum(cellsMatrix.col(0)) == 0);
        rel(*this, sum(cellsMatrix.col(1)) == 0);

        for (int i = 1; i < n+3; ++i) {
            for (int j = 1; j < n+3; ++j) {
                BoolVarArgs neighborCells;
                neighborCells << cellsMatrix(i, j - 1);
                neighborCells << cellsMatrix(i, j + 1);
                neighborCells << cellsMatrix(i - 1, j);
                neighborCells << cellsMatrix(i - 1, j-1);
                neighborCells << cellsMatrix(i - 1, j+1);
                neighborCells << cellsMatrix(i + 1, j);
                neighborCells << cellsMatrix(i + 1, j-1);
                neighborCells << cellsMatrix(i + 1, j+1);
                /*
                 * live cell with < 2 live neighbors dies
                 * live cell with > 3 live neighbors dies
                 * dead cell with 3 live neighbors becomes live
                 */
                rel(*this, cellsMatrix(i, j) >> (sum(neighborCells) >= 2 && sum(neighborCells) <= 3));
                rel(*this, !cellsMatrix(i, j) >> (sum(neighborCells) != 3));
            }
        }
        /**
         * Branching strategy
         */
        branch(*this, cells, INT_VAR_NONE(), INT_VAL_MAX());
    }

    /// Constructor for cloning
    Life(bool share, Life &space) : Script(share, space), n(space.n) {
        cells.update(*this, share, space.cells);
    }

    /// Perform copying during cloning
    virtual Space *copy(bool share) {
        return new Life(share, *this);
    }

    /// Print solution
    virtual void print(std::ostream &os) const {
        int sum = 0;
        os << "-----------------------------------------------" << std::endl;
        Matrix <BoolVarArray> cellsMatrix(cells, n + 4, n + 4);
        os << "GOL Max Still-Life Pattern:" << std::endl;
        for (int i = 2; i < n+2; ++i) {
            for (int j = 2; j < n+2; ++j) {
                os << " " << cellsMatrix(i,j);
                sum = sum + cellsMatrix(i,j).val();
            }
            os << std::endl;
        }
        os << "Number of live cells:" << sum << std::endl;

    }

    /**
     * Maximize the sum of values of the individual cells.
     * @param space
     */
    virtual void constrain(const Space& space) {
        const Life &home = static_cast<const Life&>(space);
        rel(*this, sum(cells) > sum(home.cells));
    }
};

/**
 * Program entrypoint, parses commandline options and initializes search engine with root-node.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {

    //Commandline options
    SizeOptions opt("Life");

    //Default options
    opt.solutions(0);//0 means find all solutions.
    opt.iterations(100); //how many iterations before measuring runtime
    opt.size(10); //n size
    opt.mode(ScriptMode::SM_SOLUTION); //Solution mode (i.e no GIST) is default
    opt.ipl(IPL_DEF); //Default propagation strength
    opt.parse(argc, argv);

    //parse cmd (potentially overwrite default options)
    opt.parse(argc, argv);

    //run script with BAB engine
    Script::run<Life, BAB, SizeOptions>(opt);

    /**
     * Example cmd to solve:
     * ./bin/life -mode gist -ipl dom -solutions 1 3
     * ./bin/life -mode solution -ipl speed -solutions 0 3
     * ./bin/life -mode time -ipl def -solutions 0 3
     * ./bin/life -mode stat -ipl memory -solutions 0 3
     *
     * or with default (4, solution, def, 1):
     * ./bin/life 3
     */
    return 0;
}

