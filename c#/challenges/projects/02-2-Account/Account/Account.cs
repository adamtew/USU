// Fig. 4.15: Account.cs
// Account class with a constructor to 
// initialize instance variable balance.

public class Account
{
    private decimal balance; // instance variable that stores the balance

    // constructor  
    public Account(decimal initialBalance)
    {
        Balance = initialBalance; // set balance using property
    }

    // credit (add) an amount to the account
    public void Credit(decimal amount)
    {
        Balance = Balance + amount; // add amount to balance 
    }

    // a property to get and set the account balance
    public decimal Balance
    {
        get
        {
            return balance;
        }
        private set
        {
            // validate that value is greater than or equal to 0; 
            // if it is not, balance is left unchanged
            if (value >= 0)
                balance = value;
        }
    }
}