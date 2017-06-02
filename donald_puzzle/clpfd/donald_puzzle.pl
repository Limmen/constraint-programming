:- use_module(library(clpfd)).

donald_puzzle(Vars):-
    Vars = [D,O,N,A,L,G,E,R,B,T],
    Vars ins 0..9,
    all_distinct(Vars),
    D*100000 + O*10000 + N*1000 + A*100 + L*10 + D
    + G*100000 + E*10000 + R*1000 + A*100 + L*10 + D #=
    R*100000 + O*10000 + B*1000 + E*100 + R*10 + T,
    labeling([ff], Vars),
    print(Vars).

print([D,O,N,A,L,G,E,R,B,T]):-
    format("D: ~p, O: ~p, N: ~p, A: ~p, L: ~p, G: ~p, E: ~p, R: ~p, B: ~p, T: ~p ~n", [D,O,N,A,L,G,E,R,B,T]),
    format("~p~p~p~p~p~p + ~p~p~p~p~p~p = ~p~p~p~p~p~p~n", [D,O,N,A,L,D,G,E,R,A,L,D,R,O,B,E,R,T]).