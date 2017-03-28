#include <iostream>

using namespace std;

class Value; //Prototype

class Memento //"snapshot" state class
{
    public: Memento(int val) { _state = val; }
    
    private: friend class Value;
    private: int _state;
    
};

class Value //Normal working class
{
    public: Value(int value) { _value = value; } //Constructor
    
    public: void triple() { _value = 3*_value; }     //Modifiers
    public: void quadruple() { _value = 4*_value; }
    
    int getValue() { return _value; }
    
    Memento *createMemento() { return new Memento(_value); }  //Create snapshot of state
    void reinstate(Memento *mem) { _value = mem -> _state; }  //Reload snapshot
    
    private: int _value;
    
};

class Command //Accesses mementos
{
    public: typedef void(Value:: *Action)();
    public: Command(Value *receiver, Action action) //Type of accessor (undo, redo, etc.)
    {
        _receiver = receiver;
        _action = action;
    }
    
    virtual void execute()
    {
        _mementoList[_numCommands] = _receiver -> createMemento();
        _commandList[_numCommands] = this;
        
        if(_numCommands > _maxCommands) _maxCommands = _numCommands;
        
        _numCommands++;
        (_receiver->*_action)();
    }
    
    static void undo() //Grabs last memento from current and overwrites
    {
        if (_numCommands == 0)
        {
            cout << "Nothing to undo!" << endl;
            return ;
        }
        
        _commandList[_numCommands - 1] -> _receiver -> reinstate(_mementoList[_numCommands - 1]);
        
        _numCommands--;
    }
    
    void static redo() //Grabs next memento from current and overwrites
    {
        if (_numCommands > _maxCommands)
        {
            cout << "Nothing to redo!" << endl;
            return ;
        }
        
        (_commandList[_numCommands]->_receiver->*(_commandList[_numCommands]->_action))();
        
        _numCommands++;
    }
    
    private: Value *_receiver;
    private: Action _action;
    private: static Command *_commandList[20]; //Sets buffer to 20
    private: static Memento *_mementoList[20];
    private: static int _numCommands;
    private: static int _maxCommands;
};

Command *Command::_commandList[];
Memento *Command::_mementoList[];
int Command::_numCommands = 0;
int Command::_maxCommands = 0;

int main()
{
    int val;
    cout << "Enter Value: ";
    cin >> val;
    
    Value *object = new Value(val);
    
    Command *commands[3];
    commands[1] = new Command(object, &Value::triple);
    commands[2] = new Command(object, &Value::quadruple);
    
    int pick;
    cout << endl;
    cout << "0: Exit" << endl;
    cout << "1: Triple" << endl;
    cout << "2: Quadruple" << endl;
    cout << "3: Undo" << endl;
    cout << "4: Redo" << endl << endl;
    cin >> pick;
    cout << endl;
    
    while(pick)
    {
        if (pick == 3) Command::undo();
        
        else if (pick == 4) Command::redo();
        
        else commands[pick] -> execute();
        
        cout << object -> getValue() << endl;
        
        cout << endl;
        cout << "0: Exit" << endl;
        cout << "1: Triple" << endl;
        cout << "2: Quadruple" << endl;
        cout << "3: Undo" << endl;
        cout << "4: Redo" << endl << endl;
        cin >> pick;
        cout << endl;
    }
}
