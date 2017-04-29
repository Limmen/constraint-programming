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

    Life(const SizeOptions &opt) :
            Script(opt) {
        /**
         * Branching strategy
         */
        //branch(*this, s, INT_VAL_MIN()); //Branch first on s
        //Try larger squares first, larger squares have smaller domains, try small x,y coords first (left-to-right, bottom-to-top)
        //branch(*this, xCoords, INT_VAR_SIZE_MIN(), INT_VAL_MIN()); //Assign x-coords first
        //branch(*this, yCoords, INT_VAR_SIZE_MIN(), INT_VAL_MIN()); //Assign y-coords second
    }

    /// Constructor for cloning
    Life(bool share, Life &space) : Script(share, space){
        //s.update(*this, share, space.s);
    }

    /// Perform copying during cloning
    virtual Space *
    copy(bool share) {
        return new Life(share, *this);
    }

    /// Print solution
    virtual void print(std::ostream &os) const {
        os << "Life Solution: " << std::endl;
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

    //run script with DFS engine
    Script::run<Life, DFS, SizeOptions>(opt);

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

