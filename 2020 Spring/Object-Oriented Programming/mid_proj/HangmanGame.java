package hangman;

	import java.io.FileNotFoundException;  // import this class to handle errors
	import java.io.File;
	import java.util.Scanner; // import the Scanner class to read text files
	import java.util.*;
	import java.util.ArrayList;

	//중간고사 과제 : 객체지향 2018920065 컴퓨터과학부 루안리치
	//행맨(HangMan Game) 게임을 만든다. 게임 규칙은 다음과 같다. 
	//규칙 1 : 영어 단어가 적혀 있는 words.txt 파일을 읽고, 영어 단어 하나를 화면에 표시한다. 
	//규칙 2 : 이때 화면에 나타난 영어단어의 몇개 글자를 숨긴 다음(ex: apple --> a-ple), 화면에 출력하여 사용자가 단어를 맞추게 하는 게임이다. 
	//규칙 3 : 숨김 글자의 수는 random 기능을 이용하여 전체 단어의 갯수의 30%가 넘지 않도록한다. 
	//규칙 4 : 한 단어에 대해 5번 틀리면 새로운 단어를 보여준다. 
	//규칙 5 : 게임 종료의 조건은 10문항을 맞추거나, 3번 문제를 틀리면 게임을 종료한다.
	

	public class HangmanGame {
		private static Scanner scanner;
		private static Scanner in;

		public static void main(String[] args) {

			int failCounter=0;
			int successCounter=0;
			int result;
			int replay='y';
			try {
				while(replay=='y') {
					File myObj = new File("words.txt"); //file path
					Scanner myReader = new Scanner(myObj);	//규칙 1 
					ArrayList<String> arrlist = new ArrayList<String>();
					while (myReader.hasNext()) {
						arrlist.add(myReader.next());
						}
					Random random = new Random();
					String str = arrlist.get(random.nextInt(arrlist.size())); 
					System.out.print("--------------------\n");
					System.out.println("Hangman Game Start!");
					result = startgame(str);
					System.out.println(str); // correct answer
					if(result==0) {
						System.out.print("\n");
						System.out.println("<You failed 5 times.>");
						failCounter++;
						}else {
							successCounter++;
							}
					System.out.print("\n");
					System.out.print("--your score--\n");
					System.out.print("Success: "+successCounter+" times.\n");
					System.out.print("Fail: "+failCounter+" times.\n");
					System.out.print("\n");
					if(failCounter!=3) {
						if(successCounter!=10) {
							System.out.print("Next\n");
							replay='y';
						}
						else {
							System.out.print("Win!");
		                	replay='n';
		                	System.out.print("Again(y/n)?");
							in = new Scanner(System.in);
							replay = in.next().charAt(0);
							if(replay=='y') {
								failCounter=0;
								successCounter=0;
							}	//to ask whether play again
						}
					}else {
						System.out.print("Game over.\n");
						System.out.print("Again(y/n)?");
						in = new Scanner(System.in);
						replay = in.next().charAt(0);
						if(replay=='y') {
							failCounter=0;
							successCounter=0;
						}
					}	//규칙 5, to ask whether play again
					myReader.close();
					}
			}
			catch (FileNotFoundException e) {
				System.out.println("An error occurred.");
				e.printStackTrace();
				}
		}

		static int startgame(String str) {
		  int fail=0; // fail times (of one words)
	      int success=0; // success times (of one words)
	      int length=(int)(str.length()*0.3);
	      int level= (int) (Math.random()*length)+1;	//규칙 3
	      char word[] = str.toCharArray();
	      char hidden[] = str.toCharArray();
	      int tmp[] = new int[level];
	      scanner = new Scanner(System.in);
	      char ch;	// alphabet which player insert
	      for(int i=0;i<level;i++) { 
	          tmp[i]=(int)(Math.random()*str.length());
	          for(int j=0;j<i;j++) {
	              if(tmp[j]==tmp[i]) {
	                  tmp[i]=(int)(Math.random()*str.length());
	                  j=-1;
	              }
	          }
	          hidden[tmp[i]]='-';	// hide alphabet randomly
	      }	//규칙 2
	      int i;
	      while(fail!=5) {
	          System.out.println(hidden);
	          System.out.print(">>");
	          ch=scanner.next().charAt(0);
	          for(i=0;i<tmp.length;i++) { 	// to check if the alphabet matches
	              if(word[tmp[i]]==ch) {
	                  hidden[tmp[i]]=ch;
	                  success++; // success=success+1
	              }
	          }
	          if(i==tmp.length) { // if the alphabet doesn't match
	              fail++; // fail=fail+1
	          }
	          if(success==level) { // if gets correct answer
	              break; //out of the loop
	          }
	      }
	      if(fail==5) { //규칙 4
	          return 0; // if fail more than 5 times, fail, next words
	      } else { // if gets correct answer under 5 times
	          return 1; // success, next words
	      }
	  }
		  
	  
	}



