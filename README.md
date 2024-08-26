# StockMarketAnalyzer: Predictive Stock Trading and Analysis System

## Overview
The **StockMarketAnalyzer** is a C and OpenGL-based program designed to simulate stock trading, enabling users to predict potential profits or losses based on historical price data. The project provides a simple algorithmic approach to assist users in making informed trading decisions while managing a budget effectively. It also visualizes stock price trends and user transactions, enhancing the overall user experience.

## Features
- **Stock Price Simulation**: Allows users to input stock prices over a selected period (daily prices for a month) and perform buying and selling transactions based on these prices.
- **Budget Management**: Users can set an initial budget, and the program ensures that transactions stay within this budget, warning the user if they attempt to exceed it.
- **Profit/Loss Calculation**: The program calculates and displays the user's profit or loss based on their trading decisions at the end of the period.
- **Predictive Analysis**: Uses simple predictive algorithms to estimate potential profits by analyzing past stock price trends.
- **Graphical Visualization**: Visual representation of stock price trends over time, along with markers for user transactions, utilizing OpenGL for rendering.
- **Customizable Transactions**: Users can buy or sell stocks on any given day within the month, with the flexibility to exit the simulation at any point.

## Installation
1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/StockMarketAnalyzer.git
    ```
2. Navigate to the project directory:
    ```bash
    cd StockMarketAnalyzer
    ```
3. Compile the code using a C compiler:
    ```bash
    gcc -o StockMarketAnalyzer main.c -lgraph
    ```
4. Run the executable:
    ```bash
    ./StockMarketAnalyzer
    ```

## Usage
1. The program will prompt you to enter the month and year of the transaction period.
2. Input the daily stock prices for the chosen month (or load from a file).
3. Set your budget for the month.
4. Enter your initial stock purchase details.
5. Continue buying or selling stocks based on the daily prices, while managing your budget.
6. At the end of the period, the program will calculate your total profit or loss and predict potential profits using its algorithm.

## Example
Enter month of transaction: 3 Enter year of transaction: 2023 Stock price for 31 days Enter budget for the month: 10000 Enter initial number of stocks: 50 Enter initial date of purchase: 1

vbnet
Copy code
The program will then proceed to simulate your trading experience, allowing you to make purchase and sale decisions while visualizing your potential profits or losses.

## Future Enhancements
- **Advanced Predictive Models**: Incorporating more sophisticated algorithms like moving averages or regression analysis for more accurate profit predictions.
- **Enhanced Visualization**: Adding more detailed graphs and charts, including candlestick charts, for better stock price analysis.
- **User Interface Improvements**: Developing a more user-friendly interface with better interaction and clearer prompts.
