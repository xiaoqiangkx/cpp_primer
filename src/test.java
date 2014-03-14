class test {
    public test(int a) { this.a = a; }
    private int a;

    public void change(test t) {
        t.a = 3;
    }

    public int get() { return a; }
    public static void main(String[] args) {
        test t1 = new test(1);
        test t2 = new test(2);
        t1.change(t2);
        System.out.println("The value of t2 is " + t2.get());
    }

}
