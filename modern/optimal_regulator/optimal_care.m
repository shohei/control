clear all;
format compact

A= [0 1
    -10 -1]
B = [0 1]'


Q=diag([300 60])
R=1

P = care(A,B,Q,R)

K = -inv(R)*B'*P

K2 = -lqr(A,B,Q,R)

x0 = [1 0]'

