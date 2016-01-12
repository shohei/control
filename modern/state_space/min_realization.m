function min_realization

clear all;
format compact;
J=0.1;
mu=0.2;
A=[
  0 1
  0 -mu/J
];
B=[0 1/J]';
C=[0 1];
D=0;
ss_p=ss(A,B,C,D)
tf_p=tf(ss_p)

ss_p_min = ss(ss_p,'min')
[a,b,c,d] = ssdata(ss_p_min)
tf_p_min=tf(ss_p_min)


end