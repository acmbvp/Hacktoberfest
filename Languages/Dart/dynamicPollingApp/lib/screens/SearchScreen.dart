import 'dart:convert';

import 'package:http/http.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:flutter/material.dart';
import 'package:polls_app/screens/responseSuccess.dart';

class SearchScreen extends StatefulWidget {
  Map result;
  SearchScreen({this.result});
  @override
  _SearchScreenState createState() => _SearchScreenState();
}

class _SearchScreenState extends State<SearchScreen> {

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
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.white,
        elevation: 0,
        title: Text("Search Results",style: GoogleFonts.poppins(color: Color.fromRGBO(18,18,18,1)),),
        leading: IconButton(
          onPressed: () {
            Navigator.of(context).pop();
          },
          icon: Icon(Icons.arrow_back_ios,color: Color.fromRGBO(18,18,18,1),),
        ),
      ),
      body: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Container(
            padding: EdgeInsets.only(left: 15,top: 5,right: 10),
            child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Flexible(child: Text(widget.result['data']['id'].toString()+". "+widget.result['data']['pollQuestion'],style: GoogleFonts.poppins(fontWeight: FontWeight.w500,fontSize: 22),)),
                widget.result['data']['isActive']==true?Icon(Icons.done,color: Colors.green,):Icon(Icons.not_interested,color: Colors.red,)
              ],
            ),
          ),
          SizedBox(height: 10,),
          widget.result['data']['isActive']==true?Container(
            padding: EdgeInsets.only(left: 15,top: 5,right: 10),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                InkWell(
                  onTap: () async{
                    int result=await throwResult(pID: widget.result['data']['id'].toString(),opt: "1");
                    if(result==1) {
                      Navigator.of(context).pushReplacement(MaterialPageRoute(
                          builder: (context) => Success()
                      ));
                    }
                  },
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.start,
                    children: [
                      Container(
                        height: 8,
                        width: 8,
                        decoration: BoxDecoration(
                          color: Color.fromRGBO(18,18,18,1),
                          borderRadius: BorderRadius.circular(4),
                        ),
                      ),
                      SizedBox(width: 5,),
                      Text(widget.result['data']['option_1'],style: GoogleFonts.poppins(fontSize: 18),),
                    ],
                  ),
                ),
                SizedBox(height: 4,),
                InkWell(
                  onTap: () async{
                    int result=await throwResult(pID: widget.result['data']['id'].toString(),opt: "2");
                    if(result==1) {
                      Navigator.of(context).pushReplacement(MaterialPageRoute(
                          builder: (context) => Success()
                      ));
                    }
                  },
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.start,
                    children: [
                      Container(
                        height: 8,
                        width: 8,
                        decoration: BoxDecoration(
                          color: Color.fromRGBO(18,18,18,1),
                          borderRadius: BorderRadius.circular(4),
                        ),
                      ),
                      SizedBox(width: 5,),
                      Text(widget.result['data']['option_2'],style: GoogleFonts.poppins(fontSize: 18),),
                    ],
                  ),
                ),
                SizedBox(height: 4,),
                InkWell(
                  onTap: () async{
                    int result=await throwResult(pID: widget.result['data']['id'].toString(),opt: "3");
                    if(result==1) {
                      Navigator.of(context).pushReplacement(MaterialPageRoute(
                          builder: (context) => Success()
                      ));
                    }
                  },
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.start,
                    children: [
                      Container(
                        height: 8,
                        width: 8,
                        decoration: BoxDecoration(
                          color: Color.fromRGBO(18,18,18,1),
                          borderRadius: BorderRadius.circular(4),
                        ),
                      ),
                      SizedBox(width: 5,),
                      Text(widget.result['data']['option_3'],style: GoogleFonts.poppins(fontSize: 18),),
                    ],
                  ),
                ),
                SizedBox(height: 4,),
                InkWell(
                  onTap: () async{
                    int result=await throwResult(pID: widget.result['data']['id'].toString(),opt: "4");
                    if(result==1) {
                      Navigator.of(context).pushReplacement(MaterialPageRoute(
                          builder: (context) => Success()
                      ));
                    }
                  },
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.start,
                    children: [
                      Container(
                        height: 8,
                        width: 8,
                        decoration: BoxDecoration(
                          color: Color.fromRGBO(18,18,18,1),
                          borderRadius: BorderRadius.circular(4),
                        ),
                      ),
                      SizedBox(width: 5,),
                      Text(widget.result['data']['option_4'],style: GoogleFonts.poppins(fontSize: 18),),
                    ],
                  ),
                ),
              ],
            )
          ):Container(
              padding: EdgeInsets.only(left: 15,top: 5,right: 10),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Row(
                        children: [
                          Container(
                            height: 8,
                            width: 8,
                            decoration: BoxDecoration(
                              color: Color.fromRGBO(18,18,18,1),
                              borderRadius: BorderRadius.circular(4),
                            ),
                          ),
                          SizedBox(width: 5,),
                          Text(widget.result['data']['option_1'],style: GoogleFonts.poppins(fontSize: 20),),
                        ],
                      ),
                      Text(widget.result['data']['option1_count'].toString(),style: GoogleFonts.poppins(fontSize: 20,fontWeight: FontWeight.bold),),
                    ],
                  ),
                  SizedBox(height: 8,),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Row(
                        children: [
                          Container(
                            height: 8,
                            width: 8,
                            decoration: BoxDecoration(
                              color: Color.fromRGBO(18,18,18,1),
                              borderRadius: BorderRadius.circular(4),
                            ),
                          ),
                          SizedBox(width: 5,),
                          Text(widget.result['data']['option_2'],style: GoogleFonts.poppins(fontSize: 20),),
                        ],
                      ),
                      Text(widget.result['data']['option2_count'].toString(),style: GoogleFonts.poppins(fontSize: 20,fontWeight: FontWeight.bold),),
                    ],
                  ),
                  SizedBox(height: 8,),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Row(
                        children: [
                          Container(
                            height: 8,
                            width: 8,
                            decoration: BoxDecoration(
                              color: Color.fromRGBO(18,18,18,1),
                              borderRadius: BorderRadius.circular(4),
                            ),
                          ),
                          SizedBox(width: 5,),
                          Text(widget.result['data']['option_3'],style: GoogleFonts.poppins(fontSize: 20),),
                        ],
                      ),
                      Text(widget.result['data']['option3_count'].toString(),style: GoogleFonts.poppins(fontSize: 20,fontWeight: FontWeight.bold),),
                    ],
                  ),
                  SizedBox(height: 8,),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Row(
                        children: [
                          Container(
                            height: 8,
                            width: 8,
                            decoration: BoxDecoration(
                              color: Color.fromRGBO(18,18,18,1),
                              borderRadius: BorderRadius.circular(4),
                            ),
                          ),
                          SizedBox(width: 5,),
                          Text(widget.result['data']['option_4'],style: GoogleFonts.poppins(fontSize: 20),),
                        ],
                      ),
                      Text(widget.result['data']['option4_count'].toString(),style: GoogleFonts.poppins(fontSize: 20,fontWeight: FontWeight.bold),),
                    ],
                  ),
                  SizedBox(height: 8,),
                  Divider(),
                  SizedBox(height: 8,),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Row(
                        children: [
                          Container(
                            height: 8,
                            width: 8,
                            decoration: BoxDecoration(
                              color: Color.fromRGBO(18,18,18,1),
                              borderRadius: BorderRadius.circular(4),
                            ),
                          ),
                          SizedBox(width: 5,),
                          Text("Total Votes",style: GoogleFonts.poppins(fontSize: 20),),
                        ],
                      ),
                      Text(widget.result['totalVotes'].toString(),style: GoogleFonts.poppins(fontSize: 20,fontWeight: FontWeight.bold),),
                    ],
                  ),
                  SizedBox(height: 8,),
                ],
              )
          )
        ],
      ),
    );
  }
}
