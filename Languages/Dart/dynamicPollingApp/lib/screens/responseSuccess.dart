import 'package:flutter/material.dart';
import 'package:confetti/confetti.dart';
import 'package:google_fonts/google_fonts.dart';


class Success extends StatefulWidget {
  @override
  _SuccessState createState() => _SuccessState();
}

class _SuccessState extends State<Success> {
  ConfettiController _controller;

  @override
  void initState() {
    // TODO: implement initState
    super.initState();
    _controller=ConfettiController(duration: Duration(seconds: 2));
    _controller.play();
  }

  @override
  void dispose() {
    // TODO: implement dispose
    super.dispose();
    _controller.dispose();
  }


  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.white,
        elevation: 0,
        leading: IconButton(
          onPressed: () {
            Navigator.of(context).pop();
          },
          icon: Icon(Icons.arrow_back_ios,color: Color.fromRGBO(18,18,18,1),),
        ),
      ),
      body: Stack(
        children: [
          Positioned(
            top: 250,
            left: MediaQuery.of(context).size.width/4.2,
            child: Column(
              children: [
                Container(padding: EdgeInsets.all(20),decoration:BoxDecoration(
                  shape: BoxShape.circle,
                  color: Colors.green
                ),child: Icon(Icons.done,color: Colors.white,)),
                Text("Response Recorded",textAlign: TextAlign.center,style: GoogleFonts.poppins(color: Color.fromRGBO(18,18,18,1),fontSize: 23),),
              ],
            ),
          ),
          Align(
            alignment: Alignment.center,
            child: ConfettiWidget(
              confettiController: _controller,
              emissionFrequency: 0.05,
              blastDirectionality: BlastDirectionality
                  .explosive, // don't specify a direction, blast randomly
              shouldLoop:
              true, // start again as soon as the animation is finished
              colors: const [
                Colors.green,
                Colors.blue,
                Colors.pink,
                Colors.orange,
                Colors.purple
              ], // manually specify the colors to be used
            ),
          ),
        ],
      ),
    );
  }
}
