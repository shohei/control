clear all;
format compact;

% A=[0 1;-2 -3]
% B=[1 0]'
% Vc=ctrb(A,B)
% 
% rank(Vc)
% 
% det(Vc)

A=[ 0 1 1
    -2 -3 1
    1 0 0
    ];
B=[0 1
    1 0
    0 0];

Vc=ctrb(A,B)

rank(Vc)

det(Vc)