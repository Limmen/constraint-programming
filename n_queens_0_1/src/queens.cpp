//
// queens.cpp
// Created by Kim Hammar & Mallu Goswami on 2017-03-28.
//

#include <gecode/driver.hh>
#include <gecode/int.hh>
#include <gecode/minimodel.hh>

using namespace Gecode;

/**
 * ComputationSpace/Script for the n-queens problem,
 * contains variables, posting constraints and branching strategies
 */
class Queens : public Script {
public:
    IntVarArray boardPositions;
    const int dimension;

    Queens(const SizeOptions &opt) :
            Script(opt),
            boardPositions(*this, opt.size() * opt.size(), 0, 1),
            dimension(opt.size()) {
        //initialize matrix, 0 = empty slot, 1 = position taken by queen
        Matrix<IntVarArray> boardMatrix(boardPositions, opt.size(), opt.size());

        //one queen per column and row constraint
        for (int i = 0; i < (int) opt.size(); i++) {
            rel(*this, sum(boardMatrix.col(i)) == 1);
            rel(*this, sum(boardMatrix.row(i)) == 1);
        }

        //Add the constraint that there should only be at most 1 queen per diagonal
        //for all diagonals bottom-left to top-right
        for (int i = 0; i < (int) opt.size() - 1; i++) {
            int digSize = i + 1;
            IntVarArgs diagonal(*this, digSize, 0, 1);
            for (int j = 0; j < digSize; j++) {
                diagonal << boardMatrix(i - j, j);
            }
            rel(*this, sum(diagonal) <= 1);

            digSize = opt.size() - i;
            IntVarArgs diagonal2(*this, digSize, 0, 1);
            for (int j = 0; j < digSize; j++) {
                diagonal2 << boardMatrix(i + j, (opt.size() - 1) - j);
            }
            rel(*this, sum(diagonal2) <= 1);
        }

        //Add the constraint that there should only be at most 1 queen per diagonal
        //for all diagonals bottom-right to top-left
        for (int i = 0; i < (int) opt.size(); i++) {
            //diagonal starting in (i,0)
            int diagonalSize = i + 1;
            IntVarArgs diagonal(*this, diagonalSize, 0, 1);
            for (int j = 0; j < diagonalSize; j++) {
                diagonal << boardMatrix(i - j, (opt.size() - 1) - j);
            }
            rel(*this, sum(diagonal) <= 1);

            //diagonal starting in (i,n)
            diagonalSize = opt.size() - i;;
            IntVarArgs diagonal2(*this, diagonalSize, 0, 1);
            for (int j = 0; j < diagonalSize; j++) {
                diagonal2 << boardMatrix((opt.size() - 1) - j, (opt.size() - 1) - (j + i));
            }
            rel(*this, sum(diagonal2) <= 1);
        }

        //Branching strategy
        branch(*this, boardPositions, INT_VAR_SIZE_MIN(), INT_VAL_MAX());
    }

    /// Constructor for cloning \a s
    Queens(bool share, Queens &s) : Script(share, s), dimension(s.dimension) {
        boardPositions.update(*this, share, s.boardPositions);
    }

    /// Perform copying during cloning
    virtual Space *
    copy(bool share) {
        return new Queens(share, *this);
    }

    /// Print solution
    virtual void print(std::ostream &os) const {
        os << "Queens Board Solution: " << std::endl;
        int rows = boardPositions.size() / dimension;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < dimension; j++) {
                if (boardPositions[i * dimension + j].val() == 0)
                    os << ".";
                else
                    os << "Q";
                os << " ";
            }
            os << std::endl;
        }
        os << "-----------------------------------------------------------" << std::endl;

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
    SizeOptions opt("Queens");

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
    Script::run<Queens, DFS, SizeOptions>(opt);

    /**
     * Example cmd to solve:
     * ./bin/queens -mode gist -ipl dom -solutions 1 4
     * ./bin/queens -mode solution -ipl speed -solutions 0 5
     * ./bin/queens -mode time -ipl def -solutions 0 10
     * ./bin/queens -mode stat -ipl memory -solutions 0 100
     *
     * or with default (4, solution, def, 1):
     * ./bin/queens
     */
    return 0;
}

