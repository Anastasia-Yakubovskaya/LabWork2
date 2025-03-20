# Software Testing Report
---

## Introduction

This report summarizes the testing activities for the C++ game project. The goal was to ensure that the game's features work as expected. We tested various components, including AI behavior, game mechanics, and user interface functionality. Below are the details of the tests and their results.

---

## Test Environment

### Software Environment
- **Operating System:** [Linux]
- **Compiler:** g++ (GNU C++ Compiler)
- **Testing Framework:** Google Test (gtest)
- **Build System:** Makefile


## Test Scope

We tested the following components:
- **AI Integration**
- **Cell Functionality**
- **Characteristic Effects**
- **Dice Rolling**
- **Game System**
- **User Interface (UI)**
- **Natural Disasters**
- **Player Integration**
- **Scoring System**

---

## Test Cases and Results

### AI Integration Tests

#### Test: AI Places an Object
- **What Happened:** The AI drew a construction card and placed a "Tree2" object on the board at cell (5, 5).
- **Result:** The object was placed successfully.  
- **Status:** ✅ **PASS**

#### Test: AI Draws a Card
- **What Happened:** The AI drew a construction card from the deck.
- **Result:** The card was drawn successfully.  
- **Status:** ✅ **PASS**

---

### Cell Functionality Tests

#### Test: Place an Object in a Cell
- **What Happened:** A "House1" object with 30 health was placed in a cell.
- **Result:** The cell was marked as occupied, and the content and health were updated correctly.  
- **Status:** ✅ **PASS**

#### Test: Object Takes Damage
- **What Happened:** A "House1" object with 30 health took 10 damage.
- **Result:** The health was reduced to 20.  
- **Status:** ✅ **PASS**

---

### Characteristic Effects Tests

#### Test: Apply Characteristic Effect
- **What Happened:** The "Building structures costs 10% less" characteristic was applied to a score change of -10.
- **Result:** The score was reduced by 9 (10% less).  
- **Status:** ✅ **PASS**

---

### Dice Rolling Tests

#### Test: Roll the Dice
- **What Happened:** The dice was rolled.
- **Result:** The result was between 1 and 6.  
- **Status:** **PASS**

---

### Game System Tests

#### Test: Full Game Cycle
- **What Happened:** The game started, and both the player and AI drew cards.
- **Result:** The game progressed without errors, and the deck was not empty.  
- **Status:** ✅ **PASS**

---

### User Interface (UI) Tests

#### Test: Display the Game Board
- **What Happened:** The game board was displayed.
- **Result:** The board was displayed correctly without errors.  
- **Status:** **PASS**

---

### Natural Disasters Tests

#### Test: Trigger a Natural Disaster
- **What Happened:** A "Flood" disaster was triggered, dealing 10 damage to a "House1" object.
- **Result:** The health of "House1" was reduced to 20.  
- **Status:** ✅ **PASS**

---

### Player Integration Tests

#### Test: Player Places an Object
- **What Happened:** The player drew a construction card and placed a "House1" object at cell (0, 0).
- **Result:** The object was placed successfully.  
- **Status:**✅ **PASS**

---

### Scoring System Tests

#### Test: Calculate Final Score
- **What Happened:** A "House1" (15 points) and a "Tree1" (25 points) were placed on the board.
- **Result:** The final score was calculated as 40 (15 + 25).  
- **Status:**✅ **PASS**

---

## Summary

### Test Statistics
- **Total Test Cases Executed:** 11
- **Passed:** 11
- **Failed:** 0
- **Success Rate:** 100%

