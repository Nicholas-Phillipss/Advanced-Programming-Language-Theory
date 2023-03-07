// declare class
class many_names{
   
    int length; //Length
    int width; //Width
   
    // implementation part
    public many_names() {
        //Declaring variables
        length = 8;
        width = 8;
    }
   
    // single parameter signature
    public many_names(int len) {
        //Declaring variables
        length = len;
        width = 8;
    }
   
    // two parameter signature
    public many_names(int len, int wid) {
         //Declaring variables
        length = len;
        width = wid;
    }
   
    // void for display signature
    void display() {
        System.out.println("From void display() function, Area = " + length * width);
    }
   
    // 1 parameter signature
    void display(int one) {
        System.out.println("From int display() function, Area = " + one * width);
    }
   
    // 2 parameters signature
    void display(int one,int two) {
        System.out.println("From two int display() function, Area = " + one * two);
    }
   
    // 1 parameter signature
    void display(double number) {
        System.out.println("From float display() function, Area = " + number * width);
    }
}
 
 
public class overLoading {
    // main program
    public static void main(String[] args) {
        // calling public many_names() with input variables for small, medium, and large
        many_names small = new many_names();
        many_names medium = new many_names(10); // 10 came from c++ file
        many_names large = new many_names(12,15); // 12 and 15 came from c++ file
 
        // creating and declaring variables
        int gross = 144;
        double pi = 3.1415;
        double payroll = 12.50;
 
        System.out.println("Guess, which function that has been invoked???");
        System.out.println("------------------------------------------ \n");
 
        System.out.println("small.display(void)");
        small.display(); // display function call
 
        System.out.println("\nsmall.display(100)");    
        small.display(100); // display function call
 
        System.out.println("\nsmall.display(gross, 100)");
        small.display(gross,100); // display function call
 
        System.out.println("\nsmall.display(payroll)");
        small.display(payroll); // display function call
 
        System.out.println("\nmedium.display(void)");
        medium.display(); // display function call
 
        System.out.println("\nlarge.display(pi)");  
        large.display(pi); // display function call
    }
}
