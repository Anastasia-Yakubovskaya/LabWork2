### Testing Plan for a C++ Game

### Types of Testing

### 1. Unit Testing

- Testing individual classes and methods.

- Example: Checking the methods build(), destroy() in the Building class.

### 2. Integration Testing

- Testing the interaction between classes.

- Example: Checking the interaction between Player, Game, and Board.

### 3. System Testing

- Testing the entire system as a whole.

- Example: Checking the complete game cycle (from start to finish).

### 4. User Interface Testing (UI Testing)

- Checking the correctness of the text interface display.

- Example: Checking the output of messages about the game's progress.

### Test Scenarios

### Testing the Game Board (Board)

- Test 1: Checking the placement of an object on an empty cell.

- Input: Coordinates (x, y), object "House".

- Expected Result: The object is successfully placed on the board.

- Test 2: Attempting to place an object on an occupied cell.

- Input: Coordinates (x, y), object "Tree" (the cell is already occupied).

- Expected Result: An error or message indicating that placement is not possible.

### Testing the Player (Player)

- Test 1: Selecting a cell for construction.

- Input: Coordinates (x, y).

- Expected Result: The cell is selected for construction.

- Test 2: Drawing a card from the deck.

- Input: Construction deck.

- Expected Result: The card is successfully added to the player's hand.

### Testing the Deck of Cards (Deck)

- Test 1: Drawing a card from the deck.

- Input: Construction deck.

- Expected Result: The card is successfully drawn.

- Test 2: Shuffling the deck.

- Input: Deck of random events.

- Expected Result: The cards in the deck are shuffled.

### Testing Events (EventCard, NaturalDisaster, EconomicCrisis)

- Test 1: Activating a natural disaster.

- Input: Card "Fire".

- Expected Result: Damage is inflicted on the player's buildings.

- Test 2: Activating an economic crisis.

- Input: Card "Inflation".

- Expected Result: The cost of construction is increased.

### Testing the Scoring System (ScoringSystem)

- Test 1: Updating the player's score.

- Input: Player, 10 points.

- Expected Result: The player's score is increased by 10.

- Test 2: Checking the winner.

- Input: Players with different scores.

- Expected Result: The player with the highest score is declared the winner.

### Testing AI (AI)

- Test 1: AI move.

- Input: Game board with available cells.

- Expected Result: The AI successfully selects a cell for construction.

### Testing the Game Cycle (Game)

- Test 1: Starting the game.

- Input: Players, board, decks of cards.

- Expected Result: The game is successfully started.

- Test 2: Ending the game.

- Input: All cells on the board are occupied.

- Expected Result: The game is over, and the winner is declared.

### Test Data

- Game Board:

- Empty 20x20 board.

- Board with partially occupied cells.

- Fully occupied board.

- Cards:

- Construction cards 

- Random event cards 

- Bonus cards 

- Players:

- Players with different characteristics (damage reduction, reduced construction costs, earning more points).

### Testing Tools

- **Unit Testing Frameworks**:

- Google Test

- Tools for integration testing:

- Automated tests using Google Test.
