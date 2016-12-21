function zero_characteristics
clear all;
close all;

s= tf('s');
figure(1);
hold on;

G=(-s+2)/((s+2)*(s+3));
g1=step(G);

G=(2)/((s+2)*(s+3));
g2=step(G);

G=(s+2)/((s+2)*(s+3));
g3=step(G);

G=(s+3)/((s+2)*(s+3));
g4=step(G);

G=(3*s+3)/((s+2)*(s+3));
g5=step(G);

plot(g1);
plot(g2);
plot(g3);
plot(g4);
plot(g5);
legend('z=2','z=N/A','z=-2','z=-3','z=-1/3')

end