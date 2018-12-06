program f5

implicit none
real :: i, j

do i = 1, 100, 1
        do j = 1, i, 1
                if(SQRT(i**2 + j**2) == INT(SQRT(i**2 + j**2))) then
                        if(SQRT(i**2 + j**2) <= 100) then
                                print *, i, "^2 + ", j, "^2 = " ,SQRT(i**2 + j**2), "^2"
                        end if
                end if
        end do
end do

end program
