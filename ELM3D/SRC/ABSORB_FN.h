

void absorb_fn()
{
 int i,j,k;

if(absorb_model==1.0)
{
 /// zzzz
 for(k=0; k<Nz; k++)
 {
  abz[k]=1.0;
  if(k<width)
  {
    abz[k]=exp( -lambda*(width-k)*(width-k) );
  }
  else if(k>Nz-width)
  {
    abz[k]=exp( -lambda*(-Nz+width+k)*(-Nz+width+k) );
  }
 }
 /// yyyy
 for(i=0; i<Ny; i++)
 {
  aby[i]=1.0;
  if(i<width)
  {
    aby[i]=exp( -lambda*(width-i)*(width-i) );
  }
  else if(i>Ny-width)
  {
    aby[i]=exp( -lambda*(-Ny+width+i)*(-Ny+width+i) );
  }
 }
/// xxxx
 for(j=0; j<Nx; j++)
 {
  abx[j]=1.0;
  if( (j+my_rank*Nx) < width)
  {
    abx[j]=exp(-lambda*(width-j-my_rank*Nx)*(width-j-my_rank*Nx));
  }
  else if( (j+my_rank*Nx) > Nx*(my_size)-width)
  {
abx[j]=exp(-lambda*(j+my_rank*Nx-Nx*(my_size)+width)*(j+my_rank*Nx-Nx*(my_size)+width));
  }
 }
}
else if(absorb_model==2.0)
{
/// zzzz
 for(k=0; k<Nz; k++)
 {
  abz[k]=1.0;
  if(k<width)
  {
    abz[k]=exp( -lambda*(width-k)*(width-k) );
  }
 }
 ////////////////////////////////////////////////////////////////////
 /// yyyy
 for(i=0; i<Ny; i++)
 {
  aby[i]=1.0;
  if(i<width)
  {
    aby[i]=exp( -lambda*(width-i)*(width-i) );
  }
  else if(i>Ny-width)
  {
    aby[i]=exp( -lambda*(-Ny+width+i)*(-Ny+width+i) );
  }
 }
////////////////////////////////////////////////////////////////////
/// xxxx
 for(j=0; j<Nx; j++)
 {
  abx[j]=1.0;
  if( (j+my_rank*Nx) < width)
  {
    abx[j]=exp(-lambda*(width-j-my_rank*Nx)*(width-j-my_rank*Nx));
  }
  else if( (j+my_rank*Nx) > Nx*(my_size)-width)
  {
abx[j]=exp(-lambda*(j+my_rank*Nx-Nx*(my_size)+width)*(j+my_rank*Nx-Nx*(my_size)+width));
  }
 }

}
else
{
 for(j=0; j<Nx; j++)
 {
   abx[j]=1.0;
 }
 for(i=0; i<Ny; i++)
 {
   aby[i]=1.0;
 }
 for(k=0; k<Nz; k++)
 {
   abz[k]=1.0;
 }
}

}

// NEEDS TO BE REWRITTEN MORE EFFICIENTLY
void absorb()
{
 int i,j,k;
   
        for(i=0; i<Ny; i++)
        {
        for(j=0; j<Nx; j++)
        {
	for(k=0; k<Nz; k++)
        {
	   upx[i][j][k]=upx[i][j][k]*abx[j]*aby[i]*abz[k];
           upy[i][j][k]=upy[i][j][k]*abx[j]*aby[i]*abz[k];
           upz[i][j][k]=upz[i][j][k]*abx[j]*aby[i]*abz[k];
        }
        }
	}

}
