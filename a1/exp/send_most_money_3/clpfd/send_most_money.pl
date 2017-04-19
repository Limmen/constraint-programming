:- use_module(library(clpfd)).

start:-
    Vars=[S,E,N,D,M,O,T,Y], send_most_money(Vars), label(Vars),
    format("S: ~p E: ~p N: ~p D: ~p M: ~p O: ~p T: ~p Y: ~p ~n", [S,E,N,D,M,O,T,Y]).

start(all):-
    findall(_, start, _).

send_most_money(Vars):-
    Vars = [S,E,N,D,M,O,T,Y],
    Vars ins 0..9,
    S #\= 0,
    M #\= 0,
    all_different(Vars),
    1000 *S + 100*E + 10*N + D + 1000*M + 100*O + 10*S + T #= 10000*M + 1000*O + 100*N + 10*E + Y.