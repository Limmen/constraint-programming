/*
 *  Main author:
 *     Christian Schulte <cschulte@kth.se>
 *
 *  Copyright:
 *     Christian Schulte, 2009
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */


#include <gecode/int.hh>

using namespace Gecode;
using namespace Gecode::Int;

// The no-overlap propagator
class NoOverlap : public Propagator {
protected:
    // The x-coordinates
    ViewArray<IntView> x;
    // The width (array)
    int *w;
    // The y-coordinates
    ViewArray<IntView> y;
    // The heights (array)
    int *h;
public:
    // Create propagator and initialize
    NoOverlap(Home home, ViewArray<IntView> &x0, int w0[], ViewArray<IntView> &y0, int h0[]) :
    //Initialize variables
            Propagator(home),
            x(x0),
            w(w0),
            y(y0),
            h(h0) {
        //Subscription controls the execution of hte propagator
        x.subscribe(home, *this, PC_INT_BND); //Subscribe to changes in the x-view
        y.subscribe(home, *this, PC_INT_BND); //Subscribe to changes in the y-view
    }

    // Post no-overlap propagator. Post function decides whether propagation is necessary and then creates the propagator
    // if needed
    static ExecStatus post(Home home, ViewArray<IntView> &x, int w[], ViewArray<IntView> &y, int h[]) {
        // Only if there is something to propagate
        if (x.size() > 1)
            (void) new(home) NoOverlap(home, x, w, y, h);
        return ES_OK;
    }

    // Copy constructor during cloning
    NoOverlap(Space &home, bool share, NoOverlap &p)
            : Propagator(home, share, p) {
        x.update(home, share, p.x);
        y.update(home, share, p.y);
        // Also copy width and height arrays
        w = home.alloc<int>(x.size());
        h = home.alloc<int>(y.size());
        for (int i = x.size(); i--;) {
            w[i] = p.w[i];
            h[i] = p.h[i];
        }
    }

    // Create copy during cloning
    virtual Propagator *copy(Space &home, bool share) {
        return new(home) NoOverlap(home, share, *this);
    }

    // Re-schedule function after propagator has been re-enabled
    virtual void reschedule(Space &home) {
        x.reschedule(home, *this, PC_INT_BND);
        y.reschedule(home, *this, PC_INT_BND);
    }

    // Return cost (defined as cheap quadratic complexity)
    virtual PropCost cost(const Space &, const ModEventDelta &) const {
        return PropCost::quadratic(PropCost::LO, 2 * x.size());
    }

    // Perform propagation
    virtual ExecStatus propagate(Space &home, const ModEventDelta &) {
        int assigned = 0; //Count how many of the variables are assigned to detect subsumption.
        bool canOverlap = false;
        for (int i = 0; i < x.size(); ++i) {
            bool xCanOverlap = false;
            bool yCanOverlap = false;
            if (x[i].assigned() && y[i].assigned())
                assigned++;
            for (int j = 0; j < x.size(); ++j) {
                if (j != i) {
                    //square i and j overlaps on x-axis so propagate (bounds propagation) that they cant overlap on y-axis
                    if
                            (
                            (x[i].max() <= x[j].min() && x[i].min() + w[i] > x[j].max()) ||
                            (x[j].max() <= x[i].min() && x[j].min() + w[j] > x[i].max())
                            )
                    {
                        if (y[i].max() <= y[j].min())
                            GECODE_ME_CHECK(y[j].gq(home, y[i].min() + h[i]));

                        if (y[i].min() + h[i] > y[j].max())
                            GECODE_ME_CHECK(y[i].gr(home, y[j].min()));

                        if (y[j].max() <= y[i].min())
                            GECODE_ME_CHECK(y[i].gq(home, y[j].min() + h[j]));

                        if (y[j].min() + h[j] > y[i].max())
                            GECODE_ME_CHECK(y[j].gr(home, y[i].min()));
                    }
                    //square i and j overlaps on y-axis so propagate (bounds propagation) that they cant overlap on x-axis
                    if
                            (
                            (y[i].max() <= y[j].min() && y[i].min() + h[i] > y[j].max()) ||
                            (y[j].max() <= y[i].min() && y[j].min() + h[j] > y[i].max())
                            )
                    {
                        if (x[i].max() <= x[j].min())
                            GECODE_ME_CHECK(x[j].gq(home, x[i].min() + w[i]));

                        if (x[i].min() + w[i] > x[j].max())
                            GECODE_ME_CHECK(x[i].gr(home, x[j].min()));

                        if (x[j].max() <= x[i].min())
                            GECODE_ME_CHECK(x[i].gq(home, x[j].min() + w[j]));

                        if (x[j].min() + w[j] > x[i].max())
                            GECODE_ME_CHECK(x[j].gr(home, x[i].min()));
                    }
                    if (!xCanOverlap)
                        xCanOverlap =
                                //!(Condition where x_i and x_j can never overlap)
                                //I.e if x_i and x_j can never overlap, xCanOverlap = false
                                !(
                                        ((x[i].min() > x[j].max()) || (x[i].max() + w[i] <= x[j].min()))
                                        &&
                                        ((x[j].min() > x[i].max()) || (x[j].max() + w[j] <= x[i].min()))

                                );

                    if (!yCanOverlap)
                        yCanOverlap =
                                //!(Condition where y_i and y_j can never overlap)
                                //I.e if y_i and y_j can never overlap, yCanOverlap = false
                                !(
                                        ((y[i].min() > y[j].max()) || (y[i].max() + h[i] <= y[j].min()))
                                        &&
                                        ((y[j].min() > y[i].max()) || (y[j].max() + h[j] <= y[i].min()))

                                );
                }
            }
            if (!canOverlap)//If no previous squares could overlap, update the bool by checking if these 2 squares can overlap.
                canOverlap = xCanOverlap && yCanOverlap;
        }
        if (!canOverlap)
            return home.ES_SUBSUMED(*this); //No variable domains can overlap no matter assignment, no more propagation necessary

        if (assigned == y.size())
            return home.ES_SUBSUMED(*this); //All variables assigned, no more propagation necessary.
        return ES_NOFIX; //Propagator is not idempotent, max and min bounds might change and affect propagation.
    }

    // Dispose propagator and return its size (dispose works as garbage collection, must cancel subscription first).
    virtual size_t dispose(Space &home) {
        x.cancel(home, *this, PC_INT_BND);
        y.cancel(home, *this, PC_INT_BND);
        (void) Propagator::dispose(home);
        return sizeof(*this);
    }
};

/*
 * Post the constraint that the rectangles defined by the coordinates
 * x and y and width w and height h do not overlap.
 *
 * This is the function that you will call from your model. The best
 * is to paste the entire file into your model.
 *
 * Post function checks whether arguments are correct and whether the the space is failed or not before posting the
 * propagator.
 */
void nooverlap(Space &home,
               const IntVarArgs &x, const IntArgs &w,
               const IntVarArgs &y, const IntArgs &h) {
    // Check whether the arguments make sense
    if ((x.size() != y.size()) || (x.size() != w.size()) ||
        (y.size() != h.size()))
        throw ArgumentSizeMismatch("nooverlap");
    // Never post a propagator in a failed space
    if (home.failed()) return;
    // Set up array of views for the coordinates
    ViewArray<IntView> vx(home, x);
    ViewArray<IntView> vy(home, y);
    // Set up arrays (allocated in home) for width and height and initialize
    int *wc = static_cast<Space &>(home).alloc<int>(x.size());
    int *hc = static_cast<Space &>(home).alloc<int>(y.size());
    for (int i = x.size(); i--;) {
        wc[i] = w[i];
        hc[i] = h[i];
    }
    // If posting failed, fail space
    if (NoOverlap::post(home, vx, wc, vy, hc) != ES_OK)
        home.fail();
}