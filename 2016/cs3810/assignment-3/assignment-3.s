.data
title: .asciiz "\nBubble Sort\n\n"
newLine: .asciiz "\n"
newSpace: .asciiz " "
myArray: .word 18, 1, 6, 19, 13
arraySize: .word 5
arraySizeMinusOne: .word 12

.text

main:

  # Initialize all the beginings variables needed
  la $s0, myArray # Save the array to $s0
  la $s1, 0($s0) # save the first index of the array into $s1
  la $s2, 4($s0) # save the second index of the array into $s2
  lw $s7, arraySize # save the array size in $s2
  lw $s6, arraySizeMinusOne # save the array size in $s2
  addi $t2, $zero, 0  # initialize t2 to 0
  
  # begin main functions
  jal printTitle # Print the title
  jal printArray # Print the unsorted array
  jal sortArray # Sort the array
  jal printNewLine # Print a new line
  jal printArray # Print the sorted array
  j exit # finish the program

# Procedure to print the title
printTitle:
  la $a0, title # load address of title into $a0
  li $v0, 4 # load immediate opp code of 4 into $v0
  syscall # issue a system call (using opp code 4 which print the content of $a0 to the console
  j done # return to where the procedure call was made

# Procedure to print a new line
printNewLine:
  la $a0, newLine # load address of newLine into $a0
  li $v0, 4 # load immediate opp code 4 into $v0
  syscall # issue a system call
  j done # return to the address of where the procedure  call was made

printArray:
  la $s1, 0($s0)
  addi $t2, $zero, 0  # initialize t2 to 0
  printArrayLoop:
    lw $t0, ($s1)
    addi $t2, $t2, 1 # increment the watcher variable by one
    li $v0, 1 # load immediate opp code
    move $a0, $t0 # move $t0 into $a0
    syscall # run the opp code in $v0
    li $v0, 4 # load immediate opp code
    la $a0, newSpace # load address newSpace into $a0
    syscall #issue a system call
    la $s1, 4($s1) # Iterate to the next index in the array
    # addi $s0, $s0, 1 # increment the
    bne $t2, $s7, printArrayLoop# once the watcher is the same size as the array, continue
  
  j done

done:
    jr $ra

sortArray:
  # initialize incrementing variables
  addi $t2, $zero, 0 # initialize $t2 to 0 (initialize i)
  add $t6 $zero, $zero # initialize stepping variable
  loopi:
    addi $t2, $t2, 1 # increment i
    add $t3, $zero, $zero # initialize $t3 to 0 (initialize j)
    loopj:
      # if myArray[i] < myArray[j] then swap
      #sll $t5, $t3, 2 # shift left logical $t3 by two. This is to make it easier to address an array
      add $t5, $t3, $s0 # get the address of the jth position in the array
      #lw $t6, $t5, 0 # get the value of the jth position of the array
      lw $t6, 0($t5) # get the value of the jth position of the array
      #lw $t7, $t5, 4 # grab the value of the jth + 1 position of the array
      lw $t7, 4($t5) # grab the value of the jth + 1 position of the array
      ble $t6, $t7, noSwap
      sw $t7, 0($t5) # store the contents of $t7 in the array
      sw $t6, 4($t5) # same as above
      noSwap:
      
      addi $t3, $t3, 4 # increment j
      ble $t3, $s6, loopj # while j is less than the size of the array, keep looping
    bne $t2, $s7, loopi # while i is less than thesize of the array, keep looping
  
  j done
  




exit:
