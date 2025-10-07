subroutine qpc_likelihoods2(py,s3,EsNo,No)

  integer QQ,QN
  parameter(QQ=128,QN=128)
  real py(0:QQ-1,0:QN-1)
  real s3(0:QQ-1,0:QN-1)
  real No,norm,normpwr,normpwrmax

  norm=(EsNo/(EsNo+1.0))/No

! Compute likelihoods for symbol values, from the symbol power spectra
  do k=0,QN-1
     normpwrmax=0.
     do j=0,QQ-1
        normpwr=norm*s3(j,k)
        py(j,k)=normpwr
        normpwrmax=max(normpwr,normpwrmax)
     enddo
     pynorm=0.
     do j=0,QQ-1
        py(j,k)=exp(py(j,k)-normpwrmax)
        pynorm=pynorm + py(j,k)
     enddo
     py(0:QQ-1,k)=py(0:QQ-1,k)/pynorm         !Normalize to probabilities
  enddo

  return
end subroutine qpc_likelihoods2
