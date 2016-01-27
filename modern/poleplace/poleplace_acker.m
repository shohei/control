clear all;
format compact;

A=[ -3 1
    2 -2
    ];
B=[2 0]';

p = [
 -8+4j
 -8-4j
]

C = eye(2);
D = zeros(2,1);

K = -acker(A,B,p);

eig(A+B*K)


x0 = [1 0]';