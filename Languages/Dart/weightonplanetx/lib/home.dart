import 'package:flutter/material.dart';

class Home extends StatefulWidget {
  @override
  State<StatefulWidget> createState() {
    return new HomeState();
  }
}

class HomeState extends State<Home> {

  int radiovalue = 1;
  String _result = "";
  final TextEditingController _weightController = new TextEditingController();

  void handleRadioValueChange(int value){
    setState(() {
      radiovalue = value;
    });
  }
  void _calculate(){
    setState(() {
      switch(radiovalue) {
        case 0:
          _result = "Your weight on Pluto is ${((double.parse(_weightController.text))*0.06).toStringAsFixed(1)} Kgs";
          break;
        case 1:
          _result = "Your weight on Mars is ${((double.parse(_weightController.text))*0.38).toStringAsFixed(1)} Kgs";
          break;
        case 2:
          _result = "Your weight on Venus is ${((double.parse(_weightController.text))*0.91).toStringAsFixed(1)} Kgs";
          break;
      }
    });
  }
  @override
  Widget build(BuildContext context) {
    return new Scaffold(
      appBar: new AppBar(
        title: new Text("Weight On Planet X"),
        backgroundColor: Colors.black38,
        centerTitle: true,
      ),
      backgroundColor: Colors.blueGrey,
      body: new Container(
        alignment: Alignment.topCenter,
        padding: const EdgeInsets.all(2.5),
        child: new ListView(
          children: <Widget>[
            new Image.asset(
              'images/planet.png',
              width: 200.0,
              height: 133.0,
            ),
            new Container(
              margin: EdgeInsets.all(2.5),
              alignment: Alignment.center,
              child: new Column(
                children: <Widget>[
                  new TextField(
                    controller: _weightController,
                    keyboardType: TextInputType.number,
                    decoration: new InputDecoration(
                        icon: new Icon(Icons.person_outline),
                        labelText: "Weight On Earth",
                        hintText: "In Kgs"),
                  ),
                  new Padding(padding: new EdgeInsets.all(5.0)),
                  new Row(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: <Widget>[
                      //radio buttons
                      new Radio<int>(
                          activeColor: Colors.brown,
                          value: 0, groupValue: radiovalue, onChanged: handleRadioValueChange),
                      new Text(
                        "Pluto",
                        style: new TextStyle( color: Colors.white30),
                      ),
                      new Radio<int>(
                          activeColor: Colors.red,
                          value: 1, groupValue: radiovalue, onChanged: handleRadioValueChange),
                      new Text(
                        "Mars",
                        style: new TextStyle( color: Colors.white30),
                      ),
                      new Radio<int>(
                          activeColor: Colors.orangeAccent,
                          value: 2, groupValue: radiovalue, onChanged: handleRadioValueChange),
                      new Text(
                        "Venus",
                        style: new TextStyle( color: Colors.white30),
                      )
                    ],

                  ),
                  new Padding(padding: new EdgeInsets.all(15.0)),
                  new RaisedButton(onPressed: _calculate,
                  child: new Text("Calculate"),
                  color: Colors.blueGrey.shade500,),
                  new Padding(padding: new EdgeInsets.all(15.0)),
                  new Text(
                    _weightController.text.isEmpty? "Enter your Weight" : "$_result",
                    style: new TextStyle(
                      color: Colors.white,
                      fontSize: 15.0,
                      fontWeight: FontWeight.w500
                    ),
                  )
                ],
              ),
            )
          ],
        ),
      ),
    );
  }
}
