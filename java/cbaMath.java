class cbaMath
{

      private  int FibNumbers[];
          
      public static void main(String[]Args)
      {

		           
              cbaMath a=new cbaMath();

	int w =	a.getFibbNumber(6);
        System.out.println(w);        
        

      }//end of main


      public int getFibbNumber(int i)
      {

            return FibNumbers[i];

      }

      public cbaMath()
      {

      FibNumbers=new int[10];
      FibNumbers[0]=0;
      FibNumbers[1]=1;
      FibNumbers[2]=1;
      FibNumbers[3]=2;
      FibNumbers[4]=3;
      FibNumbers[5]=5;
      FibNumbers[6]=8;
      FibNumbers[7]=13;
      }


} 
