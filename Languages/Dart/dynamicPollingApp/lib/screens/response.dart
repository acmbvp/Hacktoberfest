import 'dart:convert';

import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/widgets.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:http/http.dart';
import 'package:polls_app/screens/responseSuccess.dart';

class ResponseScreen extends StatefulWidget {
  String option_a;
  String option_b;
  String poll;
  String option_c;
  String option_d;
  int poll_id;
  ResponseScreen({this.option_a,this.option_b,this.option_c,this.option_d,this.poll_id,this.poll});
  @override
  _ResponseScreenState createState() => _ResponseScreenState();
}

class _ResponseScreenState extends State<ResponseScreen> {
  int status=0;

  Future<int> throwResult({pID,opt}) async{
    String url="http://anirudh1998.pythonanywhere.com/pollapp/vote/$pID/$opt/";
    Response response = await get(url);
    Map result=jsonDecode(response.body);
    if(result['success'] == "vote_success") {
      return 1;
    }
    else {
      return 0;
    }
}

  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: Scaffold(
        appBar: AppBar(
          backgroundColor: Colors.white,
          elevation: 0,
          leading: IconButton(
            onPressed: () {
              Navigator.of(context).pop();
            },
            icon: Icon(Icons.arrow_back_ios,color: Color.fromRGBO(18,18,18,1),),
          ),
          title: Text("Give Response",style: GoogleFonts.poppins(color: Color.fromRGBO(18,18,18,1),),),
        ),
        body: Center(
          child: Container(
            padding: EdgeInsets.only(top: 20,right: 13,left: 13,bottom: 20),
            color: Colors.cyan,
            width: MediaQuery.of(context).size.width,
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Container(
                  alignment: Alignment.centerLeft,
                  decoration: BoxDecoration(
                    color: Colors.white,
                    borderRadius: BorderRadius.circular(8),
                  ),
                  padding: EdgeInsets.only(top: 50,bottom: 50,left: 14,right: 14),
                  width: double.infinity,
                  child: Column(
                    children: [
                      Text(widget.poll_id.toString()+". "+widget.poll,textAlign: TextAlign.start,style: GoogleFonts.poppins(fontSize: 17,fontWeight: FontWeight.w500),),
                    ],
                  ),
                ),
                InkWell(
                  onTap: () async{
                    int result=await throwResult(pID: widget.poll_id.toString(),opt: "1");
                    if(result==1) {
                      Navigator.of(context).pushReplacement(MaterialPageRoute(
                          builder: (context) => Success()
                      ));
                    }
                  },
                  child: Container(
                    margin: EdgeInsets.only(top: 10),
                    decoration: BoxDecoration(
                      color: Colors.white,
                      borderRadius: BorderRadius.circular(8),
                    ),
                    padding: EdgeInsets.only(top: 10,bottom: 10,left: 14,right: 14),
                    child: Text(widget.option_a,style: GoogleFonts.poppins(fontWeight: FontWeight.w500,fontSize: 16),),
                  ),
                ),
                InkWell(
                  onTap: () async{
                    int result=await throwResult(pID: widget.poll_id.toString(),opt: "2");
                    if(result==1) {
                      Navigator.of(context).pushReplacement(MaterialPageRoute(
                          builder: (context) => Success()
                      ));
                    }
                  },
                  child: Container(
                    margin: EdgeInsets.only(top: 10),
                    decoration: BoxDecoration(
                      color: Colors.white,
                      borderRadius: BorderRadius.circular(8),
                    ),
                    padding: EdgeInsets.only(top: 10,bottom: 10,left: 14,right: 14),
                    child: Text(widget.option_b,style: GoogleFonts.poppins(fontWeight: FontWeight.w500,fontSize: 16),),
                  ),
                ),
                InkWell(
                  onTap: () async{
                    int result=await throwResult(pID: widget.poll_id.toString(),opt: "3");
                    if(result==1) {
                      Navigator.of(context).pushReplacement(MaterialPageRoute(
                          builder: (context) => Success()
                      ));
                    }
                  },
                  child: Container(
                    margin: EdgeInsets.only(top: 10),
                    decoration: BoxDecoration(
                      color: Colors.white,
                      borderRadius: BorderRadius.circular(8),
                    ),
                    padding: EdgeInsets.only(top: 10,bottom: 10,left: 14,right: 14),
                    child: Text(widget.option_c,style: GoogleFonts.poppins(fontWeight: FontWeight.w500,fontSize: 16),),
                  ),
                ),
                InkWell(
                  onTap: () async{
                    int result=await throwResult(pID: widget.poll_id.toString(),opt: "4");
                    if(result==1) {
                      Navigator.of(context).pushReplacement(MaterialPageRoute(
                        builder: (context) => Success()
                      ));
                    }
                  },
                  child: Container(
                    margin: EdgeInsets.only(top: 10),
                    decoration: BoxDecoration(
                      color: Colors.white,
                      borderRadius: BorderRadius.circular(8),
                    ),
                    padding: EdgeInsets.only(top: 10,bottom: 10,left: 14,right: 14),
                    child: Text(widget.option_d,style: GoogleFonts.poppins(fontWeight: FontWeight.w500,fontSize: 16),),
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
