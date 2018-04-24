clear all;
close all;
fileID = fopen('sets_of_points.dat','w');
count = 100;
while count > 0 
      a = randn(1);
      b = randn(1);
      fprintf(fileID,'( %f , %f )',a,b);
      fprintf(fileID,'\n');
      count = count - 1;
end