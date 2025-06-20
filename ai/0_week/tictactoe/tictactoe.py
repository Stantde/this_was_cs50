"""
Tic Tac Toe Player
"""

import math
import copy
import sys 

#new_limit = 1000 # default value
new_limit = 100
sys.setrecursionlimit(new_limit)

X = "X"
O = "O"
EMPTY = None
XorO = [O,X]

def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]


def player(board):
    """
    Returns player who has the next turn on a board.
    """    
    if terminal(board):
        return "player returns anything!"

    count_x, count_o = (0,0)
    for i in board:
        for j in i:
            if j == 'X':
                count_x += 1
            if j == 'O':
                count_o += 1
    if count_x > count_o:
        return 'O'
    return 'X'


def actions(board):
    """
    Returns set of all possible actions (i, j) available on the board.
    """
    if terminal(board):
        return "action returns anything!"
    row, column = (3,3)
    actions = set()
    for i in range(row):
        for j in range(column):
            if board[i][j] == EMPTY:
                actions.add((i,j))
    return actions

def result(board, action):
    """
    Returns the board that results from making move (i, j) on the board.
    """
    if (action[0] < 0 or\
        action[1] < 0 or\
        action[0] > 2 or\
        action[1] > 2):
        raise InvalidAction
    if board[action[0]][action[1]] is not EMPTY:
        raise InvalidAction
    if board[action[0]][action[1]] == EMPTY:
        newBoard = copy.deepcopy(board)
        newBoard[action[0]][action[1]] = player(board)
    else:
        raise InvalidAction
    return newBoard


def winner(board):
    """
    Returns the winner of the game, if there is one.
    """    
    if (vertical(board, X) or \
        horizontal(board, X) or \
        diagonal(board, X)):
            return X
    if (vertical(board, O) or \
        horizontal(board, O) or \
        diagonal(board, O)):
            return O
    else:
        return None

def terminal(board):
    """
    Returns True if game is over, False otherwise.
    """
    count = 0
    for i in board:
        for j in i:
            if j:
                count += 1
    if count == 9:
        return True
    elif winner(board):
        return True
    else:
        return False

def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    """
    #XorO = [O,X]    
    try:
        match XorO.index(winner(board)):
            case 0: # O won
                return -1
            case 1: # X won
                return 1
    except: 
        return 0
    

def minimax(board):
    """
    Returns the optimal action for the current player on the board.
    """
        
    if terminal(board):
        return None
    
    turn = player(board)
    foo = actions(board)
    options = {}
    
    if turn == X:
        for action in foo:
            options[action] = minValue(result(board,action))
        return max(options, key=options.get)
            # The maximizing player picks action a in Actions(s) that produces the highest value of Min-Value(Result(s, a)).        
    else:
        for action in foo:
            options[action] = maxValue(result(board,action))
        return min(options, key=options.get)

def vertical(board, player):
    for j in range(3):
        if (board[0][j] == player and\
            board[1][j] == player and\
            board[2][j] == player):
            return True
    return False
def horizontal(board, player):
    for i in range(3):
        if (board[i][0] == player and\
            board[i][1] == player and\
            board[i][2] == player):
            return True
    return False
def diagonal(board, player):
    #print(player, board[0][0], board[1][1] , board[2][2] )
    if (board[0][0] == player and board[1][1] == player and board[2][2] == player):
        return True
    if (board[0][2] == player and board[1][1] == player and board[2][0] == player):
        return True
    return False
def minValue(board):
    """
    Returns utility the board from recursive calls.
    """
    v = 100
    if terminal(board):
        return utility(board)
    for action in actions(board):
        try:
            v = min(v, maxValue(result(board,action)))
        except TypeError:
            continue
    return v
def maxValue(board):
    """
    Returns utility the board from recursive calls.
    """
    v = -100
    if terminal(board):
        return utility(board)
    for action in actions(board):
        try:
            v = max(v, minValue(result(board,action)))
        except TypeError:
            continue
    return v