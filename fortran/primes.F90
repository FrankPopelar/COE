program prime

implicit none
integer :: i,j,n
integer, dimension(50) :: p
logical :: b

n = 1
b = .true.
p(1) = 2
do i = 3, 100, 1
        do j = 1, n, 1
                if (MOD(i,p(j)) == 0 .and. b) then
                        b = .false.
                end if
        end do
        if (b) then
                n = n + 1
                p(n) = i
        end if
        b = .true.
end do

do i = 1, n, 1
        if(p(i) == 0) then
                exit
        end if
        print*, p(i), " "
end do
end program
