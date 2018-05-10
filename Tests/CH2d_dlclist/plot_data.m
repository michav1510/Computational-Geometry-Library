%clear all;
%close all;
figure(4)
fileID = fopen('sets_of_points.dat');
C = textscan(fileID,'%s %f %s %f %s');
si = size(C{2},1);
X = C{2};
Y = C{4};
for i = 1 : si
   plot(X(i),Y(i),'*');
%   num = num2str(i);
%    text(X(i)-X(i)/20,Y(i)+Y(i)/20,num,'HorizontalAlignment','right');
   hold on
end
fclose(fileID);


fileID = fopen('convex_hull_res.dat');
C = textscan(fileID,'%s %f %s %f %s');
si = size(C{2},1);
X = C{2};
Y = C{4};
X = [X; X(1)];
Y = [Y; Y(1)];
plot(X,Y,'r')
hold on
fclose(fileID);