//
// magic_sequence.cpp
// Created by Kim Hammar on 2017-04-23.
//

#include <gecode/driver.hh>
#include <gecode/int.hh>
#include <gecode/minimodel.hh>

using namespace Gecode;

class MagicSequence : public Script {

public:
    const int n;
    IntVarArray seq;

    MagicSequence(const SizeOptions &opt) :
            Script(opt),
            n(opt.size()),
            seq(*this, n, 0, n - 1) {

        /**
         * Basic constraint for magic sequence
         */
        for (int i = 0; i < n; ++i) {
            BoolVarArgs reified(*this, n, 0, 1);
            for (int j = 0; j < n; ++j) {
                rel(*this, seq[j], IRT_EQ, i, reified[j]);
            }
            //rel(*this, sum(reified) == seq[i]);
            linear(*this, reified, IRT_EQ, seq[i]);
        }


        /**
         * Implied constraint, sum of sequence = sequence.size()
         */
        linear(*this, seq, IRT_EQ, n);

        /**
         * Implied constraint, sum_0^n-1((i-1)*x_i) = 0
         */
        linear(*this, IntArgs::create(n, -1, 1), seq, IRT_EQ, 0);


        //Branching strategy
        branch(*this, seq, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
    }


    /// Constructor for cloning
    MagicSequence(bool share, MagicSequence &space) : Script(share, space), n(space.n) {
        seq.update(*this, share, space.seq);
    }

    /// Perform copying during cloning
    virtual Space *
    copy(bool share) {
        return new MagicSequence(share, *this);
    }

    /// Print solution
    virtual void print(std::ostream &os) const {
        os << "MagicSequence Solution:" << std::endl;
        os << "[ ";
        for (int i = 0; i < n; ++i) {
            os << seq[i] << " ";
        }
        os << "]" << std::endl;
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
    SizeOptions opt("MagicSequence");

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
    Script::run<MagicSequence, DFS, SizeOptions>(opt);

    /**
     * Example cmd to solve:
     * ./bin/magic_sequence -mode gist -ipl dom -solutions 1
     * ./bin/magic_sequence -mode solution -ipl speed -solutions 0
     * ./bin/magic_sequence -mode time -ipl def -solutions 0
     * ./bin/magic_sequence -mode stat -ipl memory -solutions 0
     *
     * or with default (4, solution, def, 1):
     * ./bin/magic_sequence
     */
    return 0;
}

