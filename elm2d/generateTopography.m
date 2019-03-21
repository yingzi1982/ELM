clear all
close all
clc



[NxStatus Nx] = system('grep \ Nx example/input/PARAMETERS.h | cut -d "(" -f2 | cut -d ")" -f1');
Nx_mpi = str2num(Nx);
nproc=9;
Nx = Nx_mpi*nproc;

x= transpose([0:Nx-1]);

topo = ones(size(x))*(Nx-100);

fileID = fopen(['example/input/topo'],'w');

for i = [1:Nx]
  fprintf(fileID, '%i %i\n', x(i), topo(i));
end

fclose(fileID);
