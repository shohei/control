function state1
clear all;
format compact;
% A=[
%   0 1 0    
%   0 0 1
%   -2 -4 -3
% ];
% B=[0 0 1]';
% C=[8 4 0];
% D=0;
% ss_p=ss(A,B,C,D);
% [A,B,C,D]= ssdata(ss_p);
% tf_p = tf(ss_p);
% zpk_p = zpk(ss_p);
% syms s
% P = C*inv(s*eye(3)-A)*B+D
% P=simplify(P)
% P=collect(P,s)

% tf_p = tf(4*[1 2], [1 3 4 2]);
% ss_p=ss(tf_p)

numP=[4 8];
denP=[1 3 4 2];
[A,B,C,D]=tf2ss(numP,denP);
ss_p = ss(A,B,C,D);
T=[
  0 0 1
  0 1 0
  1 0 0
];
ss_pb = ss2ss(ss_p,T);
[Ac,Bc,Cc,Dc] = ssdata(ss_pb)




end