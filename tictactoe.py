def init_board():
    board = []
    cell = ord('1')
    for i in range(3):
        row = []
        for j in range(3):
            row.append(chr(cell))
            cell += 1
        board.append(row)
    return board

def print_board(board):
    print()
    for i in range(3):
        print(f" {board[i][0]} | {board[i][1]} | {board[i][2]} ")
        if i != 2:
            print("---+---+---")
    print()

def check_win(board):
    # rows and columns
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2]:
            return True
        if board[0][i] == board[1][i] == board[2][i]:
            return True
    # diagonals
    if board[0][0] == board[1][1] == board[2][2]:
        return True
    if board[0][2] == board[1][1] == board[2][0]:
        return True
    return False

def is_draw(board):
    for i in range(3):
        for j in range(3):
            if '1' <= board[i][j] <= '9':
                return False
    return True

def make_move(board, player, choice):
    target = str(choice)
    for i in range(3):
        for j in range(3):
            if board[i][j] == target:
                board[i][j] = player
                return True
    return False

def main():
    player = 'X'
    game_over = False
    board = init_board()
    print("Tic Tac Toe (Player X vs Player O)")
    print_board(board)

    while not game_over:
        try:
            choice = int(input(f"Player {player}, enter a cell number (1-9): "))
        except ValueError:
            print("Invalid input. Exiting.")
            break

        if choice < 1 or choice > 9:
            print("Invalid input. Exiting.")
            break

        if not make_move(board, player, choice):
            print("Cell already taken. Try again.")
            continue

        print_board(board)

        if check_win(board):
            print(f"Player {player} wins!")
            game_over = True
        elif is_draw(board):
            print("It's a draw.")
            game_over = True
        else:
            player = 'O' if player == 'X' else 'X'

if __name__ == "__main__":
    main()
