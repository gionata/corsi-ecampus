t=linspace(0,1,41);
x=t;y=cos(3*pi*(t-0.5));z=(x-0.5).^2;
plot3(x,y,z);
grid('on');
xlabel('x'); ylabel('y'); zlabel('z');
hold('on');
plot3(0.5,1,0,'Marker','o','LineStyle','none','Color',[1 0 0]);