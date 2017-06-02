%% Run:
%% solve(2, H, W, P, reified).
%% solve(2, H, W, P, disjoint).

:- use_module(library(clpfd)).
:- use_module(library(clpb)).

%% run_tests.
%% run_tests(square_packing:solve).
%% show_coverage(run_tests).

:- begin_tests(square_packing).

test(solve) :-
    solve(2, 3, 3, _, reified),
    solve(2, 3, 3, _, disjoint),
    solve(3, 5, 5, _, reified),
    solve(3, 5, 5, _, disjoint),
    solve(4, 7, 7, _, reified),
    solve(4, 7, 7, _, disjoint).

:- end_tests(square_packing).

solve(N, H, W, P, M):-    
    [H,W] ins 1..100,
    H #= W,
    problem(N, H, W, P),
    square_packing(P, M),
    get_vars(P, Vars),
    labeling([ff, min(H), min(W)], [H,W|Vars]).

square_packing(P, disjoint):-
    square_packing_disjoint(P).

square_packing(P, reified):-
    square_packing_reified(P).

square_packing_disjoint(P):-
    disjoint2(P).

square_packing_reified(P):-    
    square_packing_reified(P, []).

square_packing_reified([], _).

square_packing_reified([X|Xs], Rest):-
    append(Xs, Rest, Rest1),
    overlap(X, Rest1),
    square_packing_reified(Xs, [X|Rest]).

overlap(X, Squares):-
    maplist(overlap(X), Squares).

overlap(square(X,N,Y,N), square(X1, N1, Y1, N1)):-
    overlap_axis(X, N, X1, N1, B1),
    overlap_axis(Y, N, Y1, N1, B2),
    sat(~(B1*B2)).
%%non_overlap_axis(X, N, X1, N1, B3),
%%non_overlap_axis(Y, N, Y1, N1, B4),
%%B1 #==> B4, %%Overlapping X-axis implies Y-axis must not overlap
%%B2 #==> B3. %%Overlapping Y-axis implies X-axis must not overlap

overlap_axis(X, N, X1, N1, B):-
    B1 #<==> (X #=< X1),
    B2 #<==> (X+N #> X1),
    B3 #<==> (B1 #/\ B2), %% X to the left of X1 and overlaps
    B4 #<==> (X1 #=< X),
    B5 #<==> (X1+N1 #> X),
    B6 #<==> (B4 #/\ B5), %% X1 to the left of X and overlaps
    B #<==> (B3 #\/ B6). %% Either X to the left of X1 and overlaps or vice versa

non_overlap_axis(X, N, X1, N1, B):-
    B1 #<==> (X+N #=< X1),
    B2 #<==> (X1+N1 #=< X),
    B #<==> (B1 #\/ B2).

problem(N, H, W, P):-
    squares(N, H, W, P).

squares(0, _, _, []).

squares(N, H, W, [square(X,N,Y,N)| Squares1]):-
    N > 0,
    X #>= 0,
    X #=< W-N,
    Y #>= 0,
    Y #=< H-N,
    N1 is N-1,
    squares(N1, W, H, Squares1).

get_vars([], []).

get_vars([square(X1, _, Y1, _)|T], [X1,Y1|Ts]):-
    get_vars(T, Ts).