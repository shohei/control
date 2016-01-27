M1=0.5; M2=1;
k = 2; mu=1;

A = [0 1 0 0
    -k/M1 -mu/M1 k/M1 mu/M1
    0 0 0 1
    k/M2 mu/M2 -k/M2 -mu/M2
    ];

B = [0
    1/M1
    0
    0];

C = [0 0 1 0];

p = [-2+2j -2-2j -2+j -2-j];

K = -acker(A,B,p)

M0 = [A B
      C 0];

H = [-K 1]*inv(M0)*[zeros(4,1);1]

disp('eigen A+B*K')
eig(A+B*K)


q=[-4+4j -4-4j -4+2j -4-2j];

L = -acker(A',C',q)'
disp('eigen A+L*C')
eig(A+L*C)

Acl = [ A B*K
        -L*C A+B*K+L*C
        ];
    
disp('eigen Acl');
eig(Acl)

