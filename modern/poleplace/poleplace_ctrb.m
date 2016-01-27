function poleplace_ctrb
clear all;
format compact;

A=[ -3 1
    2 -2
    ];
B=[2 0]';

coe = poly(A);
a1 = coe(2);
a0 = coe(3);

Mc = [a1 1
      1 0];
  
Vc = ctrb(A,B);

Tc = inv(Vc*Mc);

p1 = -8+4j;
p2 = -8-4j;

Delta = conv([1 -p1],[1 -p2]);
d1 = Delta(2);
d0 = Delta(3);

Kc = [a0-d0 a1-d1];
K  = Kc*Tc;

eig(A+B*K)


end