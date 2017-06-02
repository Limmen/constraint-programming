
#include <gecode/driver.hh>
#include <gecode/minimodel.hh>
#include <gecode/int.hh>
#include <gecode/gist.hh>
#include <set>
#include <tuple>

using namespace Gecode;

class S1 : public Space {
public:
    IntVar A, B, C, X;

    S1(void) :
            A(*this, 1, 5),
            B(*this, 1, 5),
            C(*this, 1, 5),
            X(*this, 1, 5) {

        rel(*this, A + B + C + B == X);
        branch(*this, A, INT_VAL_MIN());
        branch(*this, B, INT_VAL_MIN());
        branch(*this, C, INT_VAL_MIN());
        branch(*this, X, INT_VAL_MIN());
    }

    S1(bool share, S1 &space) : Space(share, space) {
        A.update(*this, share, space.A);
        B.update(*this, share, space.B);
        C.update(*this, share, space.C);
        X.update(*this, share, space.X);
    }

    virtual S1 *copy(bool share) {
        return new S1(share, *this);
    }

    virtual void print() const {
        std::cout << "A: " << A << "| B:" << B << "| C:" << C << "| X:" << X << std::endl;
    }

    virtual void print(std::ostream &os) const {
        os << "A: " << A << "| B:" << B << "| C:" << C << "| X:" << X << std::endl;
    }

};

class S2 : public Space {
public:
    IntVar U, A, B, C, X;

    S2(void) :
            U(*this, 1, 5),
            A(*this, 1, 5),
            B(*this, 1, 5),
            C(*this, 1, 5),
            X(*this, 1, 5) {
        rel(*this, A + B == U);
        rel(*this, U + B + C == X);

        branch(*this, A, INT_VAL_MIN());
        branch(*this, B, INT_VAL_MIN());
        branch(*this, C, INT_VAL_MIN());
        branch(*this, U, INT_VAL_MIN());
        branch(*this, X, INT_VAL_MIN());
    }

    S2(bool share, S2 &space) : Space(share, space) {
        U.update(*this, share, space.U);
        A.update(*this, share, space.A);
        B.update(*this, share, space.B);
        C.update(*this, share, space.C);
        X.update(*this, share, space.X);
    }

    virtual S2 *copy(bool share) {
        return new S2(share, *this);
    }

    virtual void print() const {
        std::cout << "A: " << A << "| B:" << B << "| C:" << C << "| X:" << X << "| U:" << U << std::endl;
    }

    virtual void print(std::ostream &os) const {
        os << "A: " << A << "| B:" << B << "| C:" << C << "| X:" << X << "| U:" << U << std::endl;
    }

};

class Composition {
public:
    Composition(void) {};

    void test(void) {
        S1 *s1 = new S1();
        S2 *s2 = new S2();

        DFS<S1> dfs1(s1);
        DFS<S2> dfs2(s2);

        std::set<std::tuple<int, int, int, int>> s1Solutions;
        std::set<std::tuple<int, int, int, int>> s2Solutions;

        std::cout << "S1 solutions" << std::endl;
        while (S1 *sol = dfs1.next()) {
            sol->print();
            s1Solutions.insert(std::tuple<int, int, int, int>(sol->A.val(), sol->B.val(), sol->C.val(), sol->X.val()));
        }

        std::cout << "S2 solutions" << std::endl;
        while (S2 *sol = dfs2.next()) {
            sol->print();
            s2Solutions.insert(std::tuple<int, int, int, int>(sol->A.val(), sol->B.val(), sol->C.val(), sol->X.val()));
        }

        if (s1Solutions == s2Solutions)
            std::cout << "S1 solution-set is equal to S2 solution-set" << std::endl;
        else
            std::cout << "S1 solution-set is NOT equal to S2 solution-set" << std::endl;

        s1 = new S1();
        s2 = new S2();

        Gist::Print<S1> p("Print solution"); //Call print function when clicking on a node (a computation space in the tree)
        Gist::Options o;
        o.inspect.click(&p);
        Gist::dfs(s1,o);
        delete s1;

        Gist::Print<S2> p2("Print solution"); //Call print function when clicking on a node (a computation space in the tree)
        Gist::Options o2;
        o2.inspect.click(&p2);
        Gist::dfs(s2,o2);
        delete s2;
    }
};


int main(int argc, char *argv[]) {
    Composition *composition = new Composition();
    composition->test();
    return 0;
}
