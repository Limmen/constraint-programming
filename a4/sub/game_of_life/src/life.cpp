//
// life.cpp
// Created by Kim Hammar & Mallu Goswami on 2017-05-01.
//

/**
 n=8
 GOL Max Still-Life Pattern:
 1 1 0 1 1 0 1 1
 1 1 0 1 1 0 1 1
 0 0 0 0 0 0 0 0
 1 1 0 1 1 0 1 1
 1 1 0 1 1 0 1 1
 0 0 0 0 0 0 0 0
 1 1 0 1 1 0 1 1
 1 1 0 1 1 0 1 1
Number of live cells:36

 n=9
 GOL Max Still-Life Pattern:
 1 1 0 0 1 1 0 1 1
 1 0 0 1 0 1 0 1 1
 0 1 0 1 0 1 0 0 0
 1 1 0 1 0 1 1 1 1
 1 0 0 1 0 0 0 0 1
 0 1 0 1 1 1 1 0 0
 1 1 0 0 0 0 1 1 0
 1 0 0 1 1 0 0 0 1
 0 1 1 0 1 1 0 1 1
Number of live cells:43
 */

#include <gecode/driver.hh>
#include <gecode/int.hh>
#include <gecode/minimodel.hh>

using namespace Gecode;

/**
 *  Script that finds maximum density still life patterns. For execution instructions see comments at bottom of file.
 *  Uses the border technique + constraint on neighbor of each cell to ensure that the pattern stays still.
 *  Uses BAB-search engine + constraint function to maximize density of the pattern.
 *  Uses implied constraint optimization that the pattern is divided into 3x3 squares with maximized density.
 */
class Life : public Script {

public:

    const int n;
    BoolVarArray cells;
    IntVarArray threeSquares;

    Life(const SizeOptions &opt) :
            Script(opt),
            n(opt.size()),
            cells(*this, (n + 4) * (n + 4), 0, 1),
            threeSquares(*this, noThreeSquares(n), 0, 6) {

        Matrix <BoolVarArray> cellsMatrix(cells, n + 4, n + 4);

        /**
         * Ensure pattern does not spread. Constraints on the border.
         * A dead cell with less than three live neighbors will not be resurrected.
         */
        rel(*this, sum(cellsMatrix.row(n + 2)) == 0);
        rel(*this, sum(cellsMatrix.row(n + 2)) == 0);
        rel(*this, sum(cellsMatrix.row(n + 3)) == 0);
        rel(*this, sum(cellsMatrix.row(0)) == 0);
        rel(*this, sum(cellsMatrix.row(1)) == 0);
        rel(*this, sum(cellsMatrix.col(n + 2)) == 0);
        rel(*this, sum(cellsMatrix.col(n + 3)) == 0);
        rel(*this, sum(cellsMatrix.col(0)) == 0);
        rel(*this, sum(cellsMatrix.col(1)) == 0);

        /**
         * Constraints on each individual cell to ensure pattern does not spread and also construction of
         * sum of 3x3 squares.
         */
        int squareNo = 0;
        for (int i = 1; i < n + 3; ++i) {
            for (int j = 1; j < n + 3; ++j) {
                /**
                 * Collect neighborhood cells
                 */
                BoolVarArgs neighborCells;
                neighborCells << cellsMatrix(i, j - 1);
                neighborCells << cellsMatrix(i, j + 1);
                neighborCells << cellsMatrix(i - 1, j);
                neighborCells << cellsMatrix(i - 1, j - 1);
                neighborCells << cellsMatrix(i - 1, j + 1);
                neighborCells << cellsMatrix(i + 1, j);
                neighborCells << cellsMatrix(i + 1, j - 1);
                neighborCells << cellsMatrix(i + 1, j + 1);
                /*
                 * live cell with < 2 live neighbors dies
                 * live cell with > 3 live neighbors dies
                 * dead cell with 3 live neighbors becomes live
                 */
                rel(*this, cellsMatrix(i, j) >> (sum(neighborCells) >= 2));
                rel(*this, cellsMatrix(i, j) >> (sum(neighborCells) <= 3));
                rel(*this, !cellsMatrix(i, j) >> (sum(neighborCells) != 3));

                /**
                 * Constrain 3x3 squares for optimization.
                 * Border of size 2 implies first 3x3 square bottom-left corner is at (2, 2), second one is at (5, 2), ... etc.
                 */
                if (j % 3 == 2 && i % 3 == 2 && j < n + 2 && i < n + 2) {
                    rel(*this, threeSquares[squareNo] ==
                               cellsMatrix(i, j) + cellsMatrix(i, j + 1) + cellsMatrix(i, j + 2) +
                               cellsMatrix(i + 1, j) + cellsMatrix(i + 1, j + 1) + cellsMatrix(i + 1, j + 2) +
                               cellsMatrix(i + 2, j) + cellsMatrix(i + 2, j + 1) + cellsMatrix(i + 2, j + 2));
                    squareNo++;
                }
            }
        }
        /**
         * Branching strategy
         */
        branch(*this, cells, INT_VAR_SIZE_MAX(), INT_VAL_MAX());
        //branch(*this, cells, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
    }

    /// Constructor for cloning
    Life(bool share, Life &space) : Script(share, space), n(space.n) {
        cells.update(*this, share, space.cells);
        threeSquares.update(*this, share, space.threeSquares);
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
        for (int i = 2; i < n + 2; ++i) {
            for (int j = 2; j < n + 2; ++j) {
                os << " " << cellsMatrix(i, j);
                sum = sum + cellsMatrix(i, j).val();
            }
            os << std::endl;
        }
        os << "Number of live cells:" << sum << std::endl;
    }

    /**
     * Auxillary function returning number of 3x3 squares given an n.
     *
     * @param n
     * @return
     */
    int noThreeSquares(int n) {
        return ceil(n / 3.0) * ceil(n / 3.0);
    }

    /**
     * Maximize the sum of values of the individual cells.
     *
     * @param space
     */
    virtual void constrain(const Space &space) {
        const Life &home = static_cast<const Life &>(space);
        rel(*this, sum(threeSquares) > sum(home.threeSquares));
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
     * ./bin/life 8
     * ./bin/life 9
     *
     */
    return 0;
}

