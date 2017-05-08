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
            s(*this, nSquaresArea(), nSquaresStacked(n)), //Problem decomposition, constraint min and max of s, s will be the first branching to enumerate subproblems.
            xCoords(*this, n - 1, 0, nSquaresStacked(n)),//min coordinate = (0,0) max = (s,s). exclude 1x1 square
            yCoords(*this, n - 1, 0, nSquaresStacked(n))//min coordinate = (0,0) max = (s,s). exclude 1x1 square
    {

        /**
         * Constraint on the origin coordinate of the squares.
         * Square must be within enclosing square (s x s) (>= 0) and must not
         * exceed x or y axis (<= s-size(i).
         */
        for (int i = 0; i < n - 1; ++i) {
            rel(*this, xCoords[i] >= 0);
            rel(*this, xCoords[i] <= s - size(i));
            rel(*this, yCoords[i] >= 0);
            rel(*this, yCoords[i] <= s - size(i));
        }

        /**
         * Apply constraints on coordinates that squares should not overlap (disjoint)
         */

        //Comment out the loops below when running with nooverlap propagator
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (j != i) {
                    BoolExpr xOverlap = (((xCoords[i] <= xCoords[j]) && (xCoords[i] + size(i) > xCoords[j])) ||
                                         ((xCoords[j] <= xCoords[i]) && (xCoords[j] + size(j) > xCoords[i])));
                    BoolExpr yOverlap = (((yCoords[i] <= yCoords[j]) && (yCoords[i] + size(i) > yCoords[j])) ||
                                         ((yCoords[j] <= yCoords[i]) && (yCoords[j] + size(j) > yCoords[i])));

                    /**
                     * If x-axis overlap then y-axis can not overlap and vice versa.
                     */
                    rel(*this, (xOverlap >> !yOverlap), opt.ipl()); //Utilize minimodel, Gecode will post this as reified integer relation constraints (ref: MPG)
                    rel(*this, (yOverlap >> !xOverlap), opt.ipl()); //Utilize minimodel, Gecode will post this as reified integer relation constraints (ref: MPG)
                }
            }
        }

        /* Use this when running with nooverlap propagator
        IntArgs w(n-1);
        IntArgs h(n-1);

        for (int i = 0; i < n-1; i++) {
            w[i] = size(i);
            h[i] = size(i);
        }

        nooverlap(*this, xCoords, w, yCoords, h);
         */

        /**
         * Apply (cumulative) constraints of max sum(squareHeight) on columns and max sum(squareWidth) on rows.
         * Redundant constraints to increase propagation, the non-overlapping coordinates implies this constraint.
         * This redundant constraint have very big impact on performance.
         */
        for (int i = 0; i < s.max(); ++i) {
            BoolVarArgs colOverlap(*this, n - 1, 0, 1);
            BoolVarArgs rowOverlap(*this, n - 1, 0, 1);
            for (int j = 0; j < n - 1; ++j) {
                dom(*this, xCoords[j], i - size(j) + 1, i, colOverlap[j]);//x <= colIndex < x means overlap
                dom(*this, yCoords[j], i - size(j) + 1, i, rowOverlap[j]);//y <= rowIndex < y means overlap
            }
            /**
             * sum of the sizes of the squares occupying space at column x must be less than or equal to s.
             * sum of the sizes of the squares occupying space at row y must be less than or equal to s.
             */
            rel(*this, sum(IntArgs::create(n - 1, n, -1), colOverlap) <= s, opt.ipl());
            rel(*this, sum(IntArgs::create(n - 1, n, -1), rowOverlap) <= s, opt.ipl());
        }

        /**
         * Symmetry breaking. Restrict placement of the largest inside-square (n x n)
         */
        rel(*this, xCoords[0] <= 1 + (s - n) / 2);
        rel(*this, yCoords[0] <= xCoords[0]);

        /**
         * Empty-strip dominance
         */

        int gapLim = n - 1 > 45 ? 45 : n - 1;
        for (int i = 2; i < gapLim; ++i) {
            rel(*this, xCoords[i] != gap_generic(i));
            rel(*this, yCoords[i] != gap_generic(i));
            if (i < 4)
                rel(*this, yCoords[i] != gap_specific(i));
        }

        /**
         * Branching strategy
         */
        branch(*this, s, INT_VAL_MIN()); //Branch first on s
        //Try larger squares first, larger squares have smaller domains, try small x,y coords first (left-to-right, bottom-to-top)
        branch(*this, xCoords, INT_VAR_SIZE_MIN(), INT_VAL_MIN()); //Assign x-coords first
        branch(*this, yCoords, INT_VAR_SIZE_MIN(), INT_VAL_MIN()); //Assign y-coords second
    }


    /**
     * helper function
     * @return square size of index i
     */
    int size(int i) {
        return n - i;
    }

    /**
     * Get the minimum area of n-squares
     * @return
     */
    int nSquaresArea() {
        return ceil(sqrt(n * (n + 1) * (2 * n + 1) / 6));
    }

    /**
     * Get the area to fit the n squares stacked on top of each other, i.e an upper bound on the size of s.
     *
     * @return
     */
    int nSquaresStacked(int i) {
        if (i == 0)
            return 0;
        return i + nSquaresStacked(i - 1);
    }

    /**
     * Prune variable domains with gaps where equivalent placement have already been investigated.
     *
     * @param i
     * @return gap
     */
    int gap_generic(int i) {
        if (i == 2)
            return 2;
        if (i == 3 || i == 4)
            return 2;
        if (i >= 5 && i <= 8)
            return 3;
        if (i >= 9 && i <= 11)
            return 4;
        if (i >= 12 && i <= 17)
            return 5;
        if (i >= 18 && i <= 21)
            return 6;
        if (i >= 22 && i <= 29)
            return 7;
        if (i >= 30 && i <= 34)
            return 3;
        if (i >= 34 && i <= 44)
            return 9;
        if (i == 45)
            return 10;
        return -1;
    }

    /**
     * Square-packing specific investigated gaps.
     *
     * @param i
     * @return gap
     */
    int gap_specific(int i) {
        if (i == 2)
            return 2;
        if (i == 3)
            return 3;
        return -1;
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
        os
                << "Square coordinates (different square 1 solutions are excluded since it can be placed anywhere (almost)):"
                << std::endl;
        for (int i = 0; i < n - 1; ++i) {
            os << "square" << n - i << ": (" << xCoords[i] << "," << yCoords[i] << ") ";
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
    opt.solutions(0);//0 means find all solutions.
    opt.iterations(100); //how many iterations before measuring runtime
    opt.size(10); //n size
    opt.mode(ScriptMode::SM_SOLUTION); //Solution mode (i.e no GIST) is default
    opt.ipl(IPL_DEF); //Default propagation strength
    opt.parse(argc, argv);


    //parse cmd (potentially overwrite default options)
    opt.parse(argc, argv);

    //run script with DFS engine
    Script::run<SquarePacking, DFS, SizeOptions>(opt);

    /**
     * Example cmd to solve:
     * ./bin/square_packing -solutions 1 15
     */
    return 0;
}

