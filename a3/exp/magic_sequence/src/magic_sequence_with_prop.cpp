//
// magic_sequence.cpp
// Created by Kim Hammar on 2017-04-23.
//

#include <gecode/int.hh>

using namespace Gecode;
using namespace Gecode::Int;

// The exactly propagator
class Exactly : public Propagator {
protected:
    ViewArray<IntView> seq;
    IntView z;
    int y;

public:
    // Create propagator and initialize
    Exactly(Home home, ViewArray<IntView> &seq0, IntView z0, int y0) :
    //Initialize variables
            Propagator(home),
            seq(seq0),
            z(z0),
            y(y0) {
        //Subscription controls the execution of hte propagator
        seq.subscribe(home, *this, PC_INT_BND);
        z.subscribe(home, *this, PC_INT_BND);
    }

    // Post exactly propagator. Post function decides whether propagation is necessary and then creates the propagator
    // if needed
    static ExecStatus post(Home home, ViewArray<IntView> &seq, IntView &z, int y) {
        (void) new(home) Exactly(home, seq, z, y);
        return ES_OK;
    }

    // Copy constructor during cloning
    Exactly(Space &home, bool share, Exactly &p)
            : Propagator(home, share, p) {
        seq.update(home, share, p.seq);
        z.update(home, share, p.z);
        y = p.y;
    }

    // Create copy during cloning
    virtual Propagator *copy(Space &home, bool share) {
        return new(home) Exactly(home, share, *this);
    }

    // Re-schedule function after propagator has been re-enabled
    virtual void reschedule(Space &home) {
        seq.reschedule(home, *this, PC_INT_BND);
        z.reschedule(home, *this, PC_INT_BND);
    }

    // Return cost (defined as cheap quadratic complexity)
    virtual PropCost cost(const Space &, const ModEventDelta &) const {
        return PropCost::linear(PropCost::LO, seq.size());
    }

    // Perform propagation
    virtual ExecStatus propagate(Space &home, const ModEventDelta &) {
        int assigned = 0;
        int countInDomain = 0;
        int countAssignedToY = 0;
        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i].assigned())
                assigned++;
            if (seq[i].in(y))
                countInDomain++;
            if (seq[i].assigned() && seq[i].val() == y)
                countAssignedToY++;
        }
        GECODE_ME_CHECK(z.lq(home, countInDomain));
        GECODE_ME_CHECK(z.gq(home, countAssignedToY));
        if(assigned == seq.size())
            return home.ES_SUBSUMED(*this);
        return ES_NOFIX;
    }

    // Dispose propagator and return its size (dispose works as garbage collection, must cancel subscription first).
    virtual size_t dispose(Space &home) {
        seq.cancel(home, *this, PC_INT_BND);
        z.cancel(home, *this, PC_INT_BND);
        (void) Propagator::dispose(home);
        return sizeof(*this);
    }
};

void exactly(Space &home, const IntVarArgs &seq, const IntVar z, const int y) {
    // Never post a propagator in a failed space
    if (home.failed()) return;
    // Set up array of views for the coordinates
    ViewArray<IntView> vseq(home, seq);
    IntView vz(z);
    // If posting failed, fail space
    if (Exactly::post(home, vseq, vz, y) != ES_OK)
        home.fail();
}


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
            exactly(*this, seq, seq[i], i);
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

