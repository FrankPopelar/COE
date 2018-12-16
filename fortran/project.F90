program prime

implicit none
integer :: i, j, n, m, iter, c
integer, dimension(10000) :: p, q, r, dist
logical :: a, b

! these needed to be hard coded in because 1 isn't a prime
p(1) = 2
q(1) = 3
r(1) = 1
dist(1) = 1
p(2) = 3
q(2) = 5
r(2) = 1
dist(2) = 2

! prelims
do i = 3,10000,1
        p(i) = 0
        q(i) = 0
        r(i) = 0
        dist(i) = 0
end do

! computations
do i = 3,10000,1        ! loop through to generate the primes
        b = .TRUE.
        if(p(i) == 0) then              ! check if the prime was generated prior
                c = p(i-1) 
                do while(b)     ! while prime not found
                        c = c + 1
                        b = .FALSE.
                        do j = 1,i-1,1  ! loop through previous primes
                                if(MOD(c,p(j)) == 0) then ! check if c is prime
                                        b = .TRUE.
                                        exit
                                end if
                        end do
                end do
                p(i) = c
        else
                c = p(i)
        end if
        iter = i+1        ! next section of loop, q generation
        a = .FALSE.
        do while(.NOT. a)       ! while r is not found
                b = .TRUE.
                if(iter > 10000) then
                        do while(b)
                                c = c + 1
                                b = .FALSE.
                                do j = 1,i,1
                                        if(MOD(c,p(j)) == 0) then
                                                b = .TRUE.
                                                exit
                                        end if
                                end do
                        end do
                else if(p(iter) == 0) then
                        do while(b)     ! generate next prime
                                c = c + 1
                                b = .FALSE.
                                do j = 1,i,1
                                        if(MOD(c,p(j)) == 0) then
                                                b = .TRUE.
                                                exit
                                        end if
                                end do
                        end do                
                        p(iter) = c
                else
                        c = p(iter)
                end if
                n = c - p(i)
                m = p(i) - n
                j = 1
                do while(m >= p(j))  ! check to see if n is prime
                        if(m == p(j)) then
                                a = .TRUE.
                                exit
                        end if
                        j = j + 1
                end do
                iter = iter + 1
        end do
        q(i) = c
        r(i) = m
        dist(i) = n
end do

! write to file
open(unit = 1, file = "p.txt")      ! file that holds all p values
open(unit = 2, file = "q.txt")      ! file that holds all q values
open(unit = 3, file = "r.txt")      ! file that holds all r values
open(unit = 4, file = "dist.txt")   ! file that holds all dist values
do i = 1,10000
        write(1,*) p(i)
        write(2,*) q(i)
        write(3,*) r(i)
        write(4,*) dist(i)
end do
close(1)
close(2)
close(3)
close(4)

end program
