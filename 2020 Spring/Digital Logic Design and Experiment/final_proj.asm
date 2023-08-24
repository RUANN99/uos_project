//2018920065 LUAN LI CHI
//PROJECT #3

(SET_UP)
@SCREEN
D=A		//D:SCREEN
@i
M=D		//RAM[i]:SCREEN
@j
M=0		//RAM[j]:0
@count
M=1		//RAM[count]:1
@x
M=0		//RAM[x]:0
@y
M=0		//RAM[y]:0
@16
D=A
@xposition	//RAM[xposition]=16
M=D
@8
D=A
@yposition	//RAM[yposition]=8
M=D

//part1: draw 32x16 grid
(DRAW_COLUMN)
//draw 32 dots each row, and 16*16 rows -> 8192 times
@i
A=M		//A:RAM[i]
M=1		//RAM[i]=1
		//1 means 0000 0000 0000 0001, a dot at left
@i
MD=M+1		//both M and D : RAM[i]+1 //let 0x4000 to 0x5fff be 1
@KBD		//KBD=0X6000 //SCREEN is from 0x4000 to 0x5fff, KBD is next to SCREEN
D=D-A		//check if complete (8192 times)
@DRAW_COLUMN
D;JLT		//if it doesn't complete yet, (D<0), repeat this loop
@SET_UP_2
D;JGE		//if D>0(complete), NEXT

(SET_UP_2)
@SCREEN
D=A		//D:SCREEN
@i
M=D		//RAM[i]:SCREEN (0X4000)

(DRAW_RAW)
//THIS PART IS TO REPEAT 32 TIMES TO COMPLETE A RAW
@33		
D=A		//D=33
@j
M=M+1		//RAM[j]=RAM[j]+1
D=M-D		//D=RAM[j]-33
@NEXT_RAW
D; JGE		//else if D>=0, jump to NEXT_RAW loop
//IF A RAW IS COMPLETED, JUMP TO NEXT_RAW LOOP

@i
A=M		//A:RAM[i]
M=-1		//RAM[A]=-1, 1111 1111 1111 1111
@i
D=M+1		//D:RAM[i]+1
M=D		//RAM[i]=RAM[i]+1
@KBD		//KBD=0X6000
D=A		//D:0x6000
@i
D=M-D		//D:RAM[i]-0X6000
@DRAW_RAW
D;JLT		//if D<0, jump to DRAW_RAW loop
@BOX_POSITION
D;JGE		//if complete, go to BOX_POSITION

(NEXT_RAW)
@512
D=A		//D=512 (32*16)
@i
M=M+D		//RAM[i]=RAM[i]+512
@j
M=0		//reset RAM[j]
@DRAW_RAW
0;JMP		//back to DRAW_ROW loop

//55
(BOX_POSITION)	//(16,8)
@20239		//SCREEN(16384)+32*16*7.5+16-1
D=A		//D=20239
@i
M=D		//RAM[i]=20239

(DRAW_BOX)	// =)
//M[M[i]]=-1 //0
@1
D=-A
@i
A=M
M=D
//M[i]+=32
@32
D=A
@i
M=D+M
//M[M[i]]=-1 //1
@1
D=-A
@i
A=M
M=D
//M[i]+=32
@32
D=A
@i
M=D+M
//M[M[i]]=-16381 //2
@16381
D=-A
@i
A=M
M=D
//M[i]+=32
@32
D=A
@i
M=D+M
//M[M[i]]=-16381 //3
@16381
D=-A
@i
A=M
M=D
//M[i]+=32
@32
D=A
@i
M=D+M
//M[M[i]]=-14749 //4
@14749
D=-A
@i
A=M
M=D
//M[i]+=32
@32
D=A
@i
M=D+M
//M[M[i]]=-14749 //5
@14749
D=-A
@i
A=M
M=D
//M[i]+=32
@32
D=A
@i
M=D+M
//M[M[i]]=-14749 //6
@14749
D=-A
@i
A=M
M=D
//M[i]+=32
@32
D=A
@i
M=D+M
//M[M[i]]=-16381 //7
@16381
D=-A
@i
A=M
M=D
//M[i]+=32
@32
D=A
@i
M=D+M
//M[M[i]]=-10213 //8
@10213
D=-A
@i
A=M
M=D
//M[i]+=32
@32
D=A
@i
M=D+M
//M[M[i]]=-10213 //9
@10213
D=-A
@i
A=M
M=D
//M[i]+=32
@32
D=A
@i
M=D+M
//M[M[i]]=-8197 //A
@8197
D=-A
@i
A=M
M=D
//M[i]+=32
@32
D=A
@i
M=D+M
//M[M[i]]=-8197 //B
@8197
D=-A
@i
A=M
M=D
//M[i]+=32
@32
D=A
@i
M=D+M
//M[M[i]]=-16381 //C
@16381
D=-A
@i
A=M
M=D
//M[i]+=32
@32
D=A
@i
M=D+M
//M[M[i]]=-16381 //D
@16381
D=-A
@i
A=M
M=D
//M[i]+=32
@32
D=A
@i
M=D+M
//M[M[i]]=-1 //E
@1
D=-A
@i
A=M
M=D
//M[i]+=32
@32
D=A
@i
M=D+M
//M[M[i]]=-1 //F
@1
D=-A
@i
A=M
M=D

@count
M=M-1
D=M

@480
D=A
@i
M=M-D		//RAM[i] (0,0) position is the left-top corner

(MOVE)
@16
D=A
@count1
M=D
@j
M=0		//RAM[j]=0
@KBD		//insert
D=M		//D:RAM[KBD]
@y
M=D

@130
D=A		//D:RAM[KBD]-130
@y
A=M-D
D=A
@LEFTLOOP
D;JEQ		//if D=0 (RAM[KBD]=130), go to LEFTLOOP loop

@131
D=A		//D:RAM[KBD]-131
@y
A=M-D
D=A
@UPLOOP
D;JEQ		//if D=0 (RAM[KBD]=131), go to UPLOOP loop

@132
D=A		//D:RAM[KBD]-132
@y
A=M-D
D=A
@RIGHTLOOP
D;JEQ		//if D=0 (RAM[KBD]=132), go to RIGHTLOOP loop

@133
D=A		//D:RAM[KBD]-133
@y
A=M-D
D=A
@DOWNLOOP
D;JEQ		//if D=0 (RAM[KBD]=133), go to DOWNLOOP loop

@140
D=D-A
@ESC		//if D=0 (RAM[KBD]=140), go to ESC loop		
D;JEQ
@MOVE	
0;JMP

(LEFTLOOP)
@KBD
M=0
@i
D=M		//D=RAM[i]
@x
M=D

@xposition	//CHECK: not allow to move outside
D=M-1
@MOVE
D;JLE
@xposition	
M=M-1

@i
M=M-1
@1
D=A
@DRAW_NEW
D;JGT

(RIGHTLOOP)
@KBD
M=0
@i
D=M
@x
M=D

@xposition	//CHECK: not allow to move outside
D=M+1
@33
D=D-A
@MOVE
D;JGE
@xposition
M=M+1
	
@i
M=M+1
@1
D=A
@DRAW_NEW
D;JGT

(UPLOOP)
@KBD
M=0
@i
D=M
@x
M=D

@yposition	//CHECK: not allow to move outside
D=M-1
@MOVE
D;JLE
@yposition
M=M-1

@544
D=A
@i
M=M-D
@1
D=A
@DRAW_NEW
D;JGT

(DOWNLOOP)
@KBD
M=0
@i
D=M
@x
M=D

@yposition	//CHECK: not allow to move outside
D=M+1
@16
D=D-A
@MOVE
D;JGE
@yposition	
M=M+1

@544
D=A
@i
M=M+D
@1
D=A
@DRAW_NEW
D;JGT

(DRAW_NEW)
@1
D=A
@DRAW_BOX
D;JGT
@BLACK_CELL
0;JMP

(BLACK_CELL)
@16
D=A
@count1
D=M-D
@MOVE
D;JLT
@x
A=M
M=-1
@BLACK_CELL
0;JMP

(ESC)
@1
D=A
@END
D;JGT

(END)
@END
0;JMP
