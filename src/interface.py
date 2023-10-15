class Exchange:
    # implement this!

    def __init__(self, initialBalance):
        """Initial Balance is the amount that each account should start with."""
        self.bal = initialBalance
        self.trades = []
        self.earnings = 0
        self.shares = 0
        self.prevTrades = {}

    def add_trade(self, trade):
        """Adds a trade to the exchange (validation required)
        and returns a match if required. It is up to you on how you will
        handle representing trades. """
        self.trades.append(trade)
        q = trade[0]
        p = trade[1]
        tradeType = trade[2]
        trade_id = trade[3]
        if tradeType == "buy":
            if self.bal < (q*p):
                print("Balance is not sufficient")
            else:
                self.bal -= (q*p)
                self.shares+=q
        elif tradeType == "sell":
            self.bal += (q*p)
            self.shares-=q
            tradeEarnings = (q*p) - self.prevTrades[trade_id]["risk"]
            self.earnings += tradeEarnings

        self.prevTrades[trade_id] = {"risk": (p*q), "type":tradeType}


        

