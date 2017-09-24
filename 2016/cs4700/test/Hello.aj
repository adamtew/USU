public aspect World {
  pointcut world() : execution(* Hello.sayHello());

  after() :  world() {
    System.out.println("Hello to you too...");
  }
}