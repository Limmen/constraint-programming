#include <gecode/driver.hh>
#include <gecode/int.hh>
#include <gecode/minimodel.hh>
#include <gecode/gist.hh>

using namespace Gecode;

class DonaldPuzzle : public Script {

protected:
    IntVarArray letters;

public:
    enum {
        GIST, CMD
    };

    DonaldPuzzle(const Options &options) :
            Script(options),
            letters(*this, 10, 0, 9) {
        IntVar d(letters[0]), o(letters[1]), n(letters[2]), a(letters[3]),
                l(letters[4]), g(letters[5]), e(letters[6]), r(letters[7]),
                b(letters[8]), t(letters[9]);

        distinct(*this, letters);
        rel(*this,
            100000 * d + 10000 * o + 1000 * n + 100 * a + 10 * l + d
            + 100000 * g + 10000 * e + 1000 * r + 100 * a + 10 * l + d ==
            100000 * r + 10000 * o + 1000 * b + 100 * e + 10 * r + t);

        //First-fail branch strategy (INT_VAR_SIZE_MIN pick variable with smallest domain first
        branch(*this, letters, INT_VAR_SIZE_MIN(), INT_VAL_SPLIT_MAX());

    }

    DonaldPuzzle(bool share, DonaldPuzzle &space) : Script(share, space) {
        letters.update(*this, share, space.letters);
    }

    virtual DonaldPuzzle *copy(bool share) {
        return new DonaldPuzzle(share, *this);
    }

    virtual void print(std::ostream &os) const {
      IntVar d = letters[0];
      IntVar o = letters[1];
      IntVar n = letters[2];
      IntVar a = letters[3];
      IntVar l = letters[4];
      IntVar g = letters[5];
      IntVar e = letters[6];
      IntVar r = letters[7];
      IntVar b = letters[8];
      IntVar t = letters[9];
      os
                << letters << std::endl;
      os << d << o << n << a << l << d << " + " << g << e << r << a << l << d << " = " << r << o << b << e << r << t << std::endl;
    }

};


int main(int argc, char *argv[]) {
    // commandline options
    Options opt("DonaldPuzzle");
    opt.model(DonaldPuzzle::GIST,
              "gist", "run as graphical interactive");
    opt.model(DonaldPuzzle::CMD,
              "cmd", "run from commandline without graphics");
    opt.model(DonaldPuzzle::CMD);
    opt.solutions(1);//Find one solution only, set to 0 to find all solutions.
    opt.parse(argc, argv);

    DonaldPuzzle *model = new DonaldPuzzle(opt);
    switch (opt.model()) {
        case DonaldPuzzle::GIST:
            Gist::dfs(model);
            break;

        case DonaldPuzzle::CMD:
            // run script
            Script::run<DonaldPuzzle, DFS, Options>(opt);
            break;
    }
    return 0;
}
