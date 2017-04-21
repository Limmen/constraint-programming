//
// square_packing.cpp
// Created by Kim Hammar & Mallu Goswami on 2017-04-21.
//

#include <gecode/driver.hh>
#include <gecode/int.hh>
#include <gecode/minimodel.hh>

using namespace Gecode;

class SquarePacking : public Script {

public:
    const int n;
    IntVar s;
    IntVarArray xCoords, yCoords;

    SquarePacking(const SizeOptions &opt) :
            Script(opt),
            n(opt.size()),
            s(*this, opt.size(), 100),
            xCoords(*this, n, 0, 100),
            yCoords(*this, n, 0, 100) {

        /**
         * Constraint on the origin coordinate of the squares.
         * Square must be within enclosing square (s x s) (>= 0) and must not
         * exceed x or y axis (<= s-size(i).
         */

        for (int i = 0; i < n; ++i) {
            rel(*this, xCoords[i] >= 0);
            rel(*this, xCoords[i] <= s - size(i));
            rel(*this, yCoords[i] >= 0);
            rel(*this, yCoords[i] <= s - size(i));
        }

        for (int i = 0; i < n; ++i) {
            std::cout << "square overlap constraint: " << size(i) << std::endl;
            for (int j = 0; j < n; ++j) {
                if (j != i) {

                    BoolExpr xOverlap = (((xCoords[i] <= xCoords[j]) && (xCoords[i] + size(i) > xCoords[j])) ||
                                         ((xCoords[j] <= xCoords[i]) && (xCoords[j] + size(j) > xCoords[i])));
                    BoolExpr yOverlap = (((yCoords[i] <= yCoords[j]) && (yCoords[i] + size(i) > yCoords[j])) ||
                                         ((yCoords[j] <= yCoords[i]) && (yCoords[j] + size(j) > yCoords[i])));
                    /**
                     * If x-axis overlap then y-axis can not overlap and vice versa.
                     */
                    rel(*this, (xOverlap && !yOverlap) || (yOverlap && !xOverlap), opt.ipl());
                }
            }
        }

        //Branching strategy
        branch(*this, s, INT_VAL_MIN());
        branch(*this, xCoords, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
        branch(*this, yCoords, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
    }


    /**
     * helper function
     * @return square size of index i
     */
    int size(int i) {
        return n - i;
    }

    /// Constructor for cloning
    SquarePacking(bool share, SquarePacking &space) : Script(share, space), n(space.n) {
        s.update(*this, share, space.s);
        xCoords.update(*this, share, space.xCoords);
        yCoords.update(*this, share, space.yCoords);
    }

    /// Perform copying during cloning
    virtual Space *
    copy(bool share) {
        return new SquarePacking(share, *this);
    }

    /// Print solution
    virtual void print(std::ostream &os) const {
        os << "SquarePacking Solution: " << std::endl;
        os << "Enclosing square size: " << s << "x" << s << std::endl;
        os << "Square coordinates:" << std::endl;
        for (int i = 0; i < n; ++i) {
            os << "square" << i << ": (" << xCoords[i] << "," << yCoords[i] << ") ";
        }
        os << std::endl;

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
    SizeOptions opt("SquarePacking");

    //Default options
    opt.solutions(0);
    opt.iterations(100); //how many iterations before measuring runtime
    opt.size(100); //nxn board
    opt.mode(ScriptMode::SM_SOLUTION);
    opt.ipl(IPL_DEF);
    opt.parse(argc, argv);


    //parse cmd (potentially overwrite default options)
    opt.parse(argc, argv);

    //run script with DFS engine
    Script::run<SquarePacking, DFS, SizeOptions>(opt);

    /**
     * Example cmd to solve:
     * ./bin/square_packing -mode gist -ipl dom -solutions 1
     * ./bin/square_packing -mode solution -ipl speed -solutions 0
     * ./bin/square_packing -mode time -ipl def -solutions 0
     * ./bin/square_packing -mode stat -ipl memory -solutions 0
     *
     * or with default (4, solution, def, 1):
     * ./bin/square_packing
     */
    return 0;
}

