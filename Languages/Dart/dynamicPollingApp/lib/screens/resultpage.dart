import 'dart:convert';

import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:flutter_circular_chart/flutter_circular_chart.dart';
import 'package:http/http.dart';
import 'dart:async';

class ResultsPage extends StatefulWidget {
  int poll_id;
  ResultsPage({this.poll_id});
  @override
  _ResultsPageState createState() => _ResultsPageState();
}

class _ResultsPageState extends State<ResultsPage> {
  final GlobalKey<AnimatedCircularChartState> _chartKey = new GlobalKey<AnimatedCircularChartState>();
  int option_a;
  int option_b;
  int option_c;
  int option_d;
  String optionA;
  String optionB;
  String optionC;
  String optionD;


  List<CircularStackEntry> data = <CircularStackEntry>[
    new CircularStackEntry(
      <CircularSegmentEntry>[
        new CircularSegmentEntry(500.0, Colors.red[200], rankKey: 'Q1'),
        new CircularSegmentEntry(1000.0, Colors.green[200], rankKey: 'Q2'),
        new CircularSegmentEntry(2000.0, Colors.blue[200], rankKey: 'Q3'),
        new CircularSegmentEntry(1000.0, Colors.yellow[200], rankKey: 'Q4'),
      ],
      rankKey: 'Quarterly Profits',
    ),
  ];



  Future<void> getResults() async{
    String poll_id=widget.poll_id.toString();
    String url="http://anirudh1998.pythonanywhere.com/pollapp/getpolldetails/$poll_id/";
    Response response =await  get(url);
    Map results=jsonDecode(response.body);
    if(mounted) {
      setState(() {
        option_a=results['data']['option1_count'];
        option_b=results['data']['option2_count'];
        option_c=results['data']['option3_count'];
        option_d=results['data']['option4_count'];
        optionA=results['data']['option_1'];
        optionB=results['data']['option_2'];
        optionC=results['data']['option_3'];
        optionD=results['data']['option_4'];
      });
    }
    List<CircularStackEntry> nextData = <CircularStackEntry>[
      new CircularStackEntry(
        <CircularSegmentEntry>[
          new CircularSegmentEntry((option_a+0.01), Colors.pinkAccent, rankKey: 'option_a'),
          new CircularSegmentEntry((option_b+0.01), Colors.green, rankKey: 'option_b'),
          new CircularSegmentEntry((option_c+0.01), Colors.cyan, rankKey: 'option_c'),
          new CircularSegmentEntry((option_d+0.01), Colors.amber, rankKey: 'option_d'),
        ],
        rankKey: 'Quarterly Profits',
      ),
    ];
    if(mounted) {
      setState(() {
        _chartKey.currentState.updateData(nextData);
      });
    }
  }



  @override
  void initState() {
    // TODO: implement initState
    super.initState();
    getResults();
    Timer.periodic(Duration(seconds: 1), (timer) {
      getResults();
    });
  }


  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.white,
        leading: IconButton(
          onPressed: () {
            Navigator.of(context).pop();
          },
          icon: Icon(Icons.arrow_back_ios,color: Color.fromRGBO(18,18,18,1),),
        ),
        elevation: 0,
        title: Text("Results",style: GoogleFonts.poppins(color: Color.fromRGBO(18,18,18,1)),),
      ),
      body: SingleChildScrollView(
        child: Padding(
          padding: EdgeInsets.only(left: 10,right: 10,top: 5),
          child: Container(
            height: MediaQuery.of(context).size.height-85,
            width: MediaQuery.of(context).size.width,
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Text("Poll results are",style: GoogleFonts.poppins(color: Color.fromRGBO(18,18,18,1),fontSize: 35),),
                Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    option_a==null?Container(padding:EdgeInsets.only(top: 30),child: Center(child: CircularProgressIndicator())):AnimatedCircularChart(
                      key: _chartKey,
                      size: const Size(300.0, 300.0),
                      initialChartData: data,
                      chartType: CircularChartType.Pie,
                    ),
                  ],
                ),
                option_a==null?Center():Container(
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.center,
                    children: [
                        Text("Poll Options",style: GoogleFonts.poppins(fontSize: 16,color: Colors.black,fontWeight: FontWeight.bold),),
                      SizedBox(height: 8,),
                        Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                        children: [
                          Container(
                            height: 10,
                            width: 10,
                            color: Colors.pinkAccent,
                          ),
                          SizedBox(width: 5,),
                          Text(optionA+" "+option_a.toString(),style: GoogleFonts.poppins(color: Colors.black,fontWeight: FontWeight.bold),),
                        ],
                      ),
                      SizedBox(height: 8,),
                      Row(
                        mainAxisAlignment: MainAxisAlignment.center,
                        children: [
                          Container(
                            height: 10,
                            width: 10,
                            color: Colors.green,
                          ),
                          SizedBox(width: 5,),
                          Text(optionB+" "+option_b.toString(),style: GoogleFonts.poppins(color: Colors.black,fontWeight: FontWeight.bold),),
                        ],
                      ),
                      SizedBox(height: 8,),
                      Row(
                        mainAxisAlignment: MainAxisAlignment.center,
                        children: [
                          Container(
                            height: 10,
                            width: 10,
                            color: Colors.cyan,
                          ),
                          SizedBox(width: 5,),
                          Text(optionC+" "+option_c.toString(),style: GoogleFonts.poppins(color: Colors.black,fontWeight: FontWeight.bold),),
                        ],
                      ),
                      SizedBox(height: 8,),
                      Row(
                        mainAxisAlignment: MainAxisAlignment.center,
                        children: [
                          Container(
                            height: 10,
                            width: 10,
                            color: Colors.amber,
                          ),
                          SizedBox(width: 5,),
                          Text(optionD+" "+option_d.toString(),style: GoogleFonts.poppins(color: Colors.black,fontWeight: FontWeight.bold),),
                        ],
                      ),
                    ],
                  ),
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }
}
