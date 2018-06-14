clear all;
close all;

fileID = fopen('plotting_for_matlab.txt');
C = textscan(fileID,'%s %f %s %f %s %f %f');
si = size(C{2},1);
X = C{2};
Y = C{4};
VAL = C{6};
COORD = C{7};
hold on;
for i = 1 : si
    if( COORD(i) ~= 0 )
        if ( COORD(i) == 1)
            plot([VAL(i) VAL(i)],[-5 5]);
            hold on;
        elseif ( COORD(i) == 2 )
            plot([-5 5],[VAL(i) VAL(i)]);
            hold on;
        end
    else 
        plot(X(i),Y(i),'*');
        hold on;
    end
end
axis([-10 10 -10 10]);
fclose(fileID);