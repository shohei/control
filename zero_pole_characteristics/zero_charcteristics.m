function zero_characteristics
clear all;
close all;

s= tf('s');
figure(1);
hold on;

G=(-1*s+2)/((s+1)*(s+2));
g1=step(G);

G=2/((s+1)*(s+2));
g2=step(G);

G=(s+2)/((s+1)*(s+2));
g3=step(G);

G=(2*s+2)/((s+1)*(s+2));
g4=step(G);

G=(3*s+2)/((s+1)*(s+2));
g5=step(G);

plot(g1);
plot(g2);
plot(g3);
plot(g4);
plot(g5);
legend('z=2','z=N/A','z=-2','z=-1','z=-2/3')

end