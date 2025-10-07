subroutine sfox_assemble(ntype,k,msg,mycall0,mygrid0,line)

! In subsequent calls, assemble all necessary information for a SuperFox
! transmission.

  character*120 line
  character*26 msg
  character*26 msg0,msg1,msg2(5),msg3(5)
  character*4 rpt2(5)
  character*6 hiscall(10)
  character*13 mycall0,mycall
  character*4 mygrid0,mygrid
  integer ntype             !Message type: 0 Free Text
                            !              1 CQ MyCall MyGrid    
                            !              2 Call_1 MyCall RR73
                            !              3 Call_1 MyCall rpt
  integer nmsg(0:3)         !Number of messages of type ntype
  data nmsg/0,0,0,0/,nbits/0/,ntx/0/,nb_mycall/0/
  save

  if(mycall0(1:1).ne.' ') mycall=mycall0
  if(mygrid0(1:1).ne.' ') mygrid=mygrid0
  if(ntype.ge.1) nb_mycall=28           !### Allow for nonstandard MyCall ###
  if(sum(nmsg).eq.0) then
     hiscall='      '
     rpt2='    '
  endif

  if(k.le.10) then
     if(ntype.eq.0) then
        if(nbits+nb_mycall.le.191) then  !Enough room for a free text message?
           nmsg(ntype)=nmsg(ntype)+1
           nbits=nbits+142
           msg0=msg
        endif
     else if(ntype.eq.1) then
        if(nbits+nb_mycall.le.318) then  !Enough room for a CQ ?
           nmsg(ntype)=nmsg(ntype)+1
           nbits=nbits+15
           msg1=msg
        endif
     else if(ntype.eq.2) then
        if(nbits+nb_mycall.le.305) then  !Enough room for a RR73 message?
           nmsg(ntype)=nmsg(ntype)+1
           nbits=nbits+28
           j=nmsg(ntype)
           msg2(j)=msg
           i1=index(msg,' ')
           hiscall(j+5)=msg(1:i1-1)
        endif
     else if(ntype.eq.3) then
        if(nbits+nb_mycall.le.300) then  !Enough room for a message with report?
           nmsg(ntype)=nmsg(ntype)+1
           nbits=nbits+33
           j=nmsg(ntype)
           msg3(j)=msg
           i1=index(msg,' ')
           hiscall(j)=msg(1:i1-1)
           i1=max(index(msg,'-'),index(msg,'+'))
           rpt2(j)=msg(i1:i1+3)
        endif
     endif
     return
  endif

  if(k.ge.11) then
! All pieces are now available. Put them into a command line for external
! program sfox_tx.
     ntx=ntx+1                                      !Transmission number
     nbits=nbits+nb_mycall                          !Add bits for MyCall

     if(nmsg(1).ge.1) then
        line=msg1
     else
        line=trim(mycall)
        do i=1,nmsg(3)
           line=trim(line)//'  '//trim(hiscall(i))//' '//rpt2(i)
        enddo
        do i=1,nmsg(2)
           line=trim(line)//'  '//trim(hiscall(i+5))
        enddo
     endif

     nmsg=0
     nbits=0
     nb_mycall=0
     hiscall='      '
     rpt2='    '
  endif

  return
end subroutine sfox_assemble
