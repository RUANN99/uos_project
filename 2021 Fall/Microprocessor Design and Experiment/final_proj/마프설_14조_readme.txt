마프설 14조 기말 프로젝트
readme.txt by 루안리치 21/12/22

About bottom:

Sw1 / stop sw-f or stop songs playing
Sw2 / stop recording

Sw-f-0 / DO
Sw-f-1 / RE
Sw-f-2 / MI
Sw-f-3 / FA
Sw-f-4 / SOL
Sw-f-5 / LA
Sw-f-6 / SI
Sw-f-7 / DDO

Sw-g-0 / song : little star
Sw-g-1 / *error
Sw-g-2 / song : we wish you a merry christmas
Sw-g-3 / show recorded
Sw-g-4 / start recording
Sw-g-5 / *no response
Sw-g-6 / *no response
Sw-g-7 / *no response

About light:

Ready 0x99 / 1001 1001

DO 0x01 / 0000 0001
RE 0x02 / 0000 0010
MI 0x04 / 0000 0100
FA 0x08 / 0000 1000
SOL 0x10 / 0001 0000
LA 0x20 / 0010 0000
SI 0x40 / 0100 0000
DDO 0x80 / 1000 0000

Reset 0xff / 1111 1111

Little star 0x33 / 0011 0011
We wish you a merry christmas 0xcc / 1100 1100

Show record 0x81 / 1000 0001
Record: wait for data 0x3c / 0011 1100
Record: keyboard pressed 0x3f / 0011 1111
Record: finish 0xff->0x00->0xff

About tone and pretone:
손으로 버튼을 누르는 시간 조절하기 어려워서 박자가 이상하게 나옴.
그래서 tone == pretone 면 record 리스트에 저장되지 않도록 만들었습니다.
하지만 중복한 노트를 입력해야 될때 sw1 버튼을 누르고 pretone=EOS로 설정하면
중복입력 가능하게 됩니다.

About f_table:
I modified the data for better tune (with my perfect pitch)
// c 19 , c# 33, d 45, d# 56, e 69, f 79, f# 88, g 99, g# 107, a 117, a# 124, b 132, c 139

