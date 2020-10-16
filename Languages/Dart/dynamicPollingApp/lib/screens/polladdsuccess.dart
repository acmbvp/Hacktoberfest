import 'package:google_fonts/google_fonts.dart';
import 'package:flutter/material.dart';
import 'package:http/http.dart';

class PollAddSuccess extends StatefulWidget {
  Map Result;
  PollAddSuccess({this.Result});
  @override
  _PollAddSuccessState createState() => _PollAddSuccessState();
}

class _PollAddSuccessState extends State<PollAddSuccess> {
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
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            Container(
              height: 70,
                width: 70,
                decoration: BoxDecoration(
                  color: Colors.green,
                  shape: BoxShape.circle,
                ),
                child: Icon(Icons.done,color: Colors.white,size: 30,)),
            SizedBox(height: 10,),
            Text("Poll Added Successfully!",style: GoogleFonts.poppins(fontSize: 25,color: Color.fromRGBO(18,18,18,1)),),
            SizedBox(height: 20,),
            Column(
              crossAxisAlignment: CrossAxisAlignment.center,
              children: [
                Text("Copy the following link",style: GoogleFonts.poppins(color: Colors.grey[700],fontSize: 15),),
                SelectableText("http://anirudh1998.pythonanywhere.com/pollapp/vote?poll_id="+widget.Result['id'].toString()+"",textAlign: TextAlign.center,style: GoogleFonts.montserrat(fontWeight: FontWeight.w600,fontSize: 14),),
              ],
            ),
            SizedBox(height: 20,),
            Column(
              crossAxisAlignment: CrossAxisAlignment.center,
              children: [
                Text("Or Just Search For "+widget.Result['id'].toString()+" in homescreen",style: GoogleFonts.poppins(color: Colors.black,fontSize: 17,fontWeight: FontWeight.w600),),
              ],
            ),
          ],
        ),
      ),
    );
  }
}
