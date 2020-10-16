import 'dart:convert';

import 'package:flutter/cupertino.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:flutter/material.dart';
import 'package:http/http.dart';
import 'package:polls_app/screens/polladdsuccess.dart';

class AddPollScreen extends StatefulWidget {
  @override
  _AddPollScreenState createState() => _AddPollScreenState();
}

class _AddPollScreenState extends State<AddPollScreen> {
  TextEditingController ques=TextEditingController();
  TextEditingController a=TextEditingController();
  TextEditingController b=TextEditingController();
  TextEditingController c=TextEditingController();
  TextEditingController d=TextEditingController();

  Future<Map> addPoll() async{
    String url="http://anirudh1998.pythonanywhere.com/pollapp/create";
    Map<String,dynamic> body = {
      'pollQuestion':ques.text,
      'option_1':a.text,
      'option_2':b.text,
      'option_3':c.text,
      'option_4':d.text,
      'option1_count':'0',
      'option2_count':'0',
      'option3_count':'0',
      'option4_count':'0',
      'isActive':true.toString()
    };
    Response response=await post(url,body: body);
    Map result=jsonDecode(response.body);
    return result;
  }



  @override
  void initState() {
    // TODO: implement initState
    super.initState();
    ques=TextEditingController();
    a=TextEditingController();
    b=TextEditingController();
    c=TextEditingController();
    d=TextEditingController();
  }

  @override
  void dispose() {
    // TODO: implement dispose
    super.dispose();
    ques.dispose();
    a.dispose();
    b.dispose();
    c.dispose();
    d.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.white,
        elevation: 1,
        title: Text("Add a Pole",style: GoogleFonts.poppins(color: Color.fromRGBO(18,18,18,1)),),
        leading: IconButton(
          onPressed: () {
            Navigator.of(context).pop();
          },
          icon: Icon(Icons.arrow_back_ios,color: Color.fromRGBO(18,18,18,1),),
        ),
      ),
      body: SingleChildScrollView(
        child: Padding(
          padding: const EdgeInsets.only(left: 5,top: 5,right: 5),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Text("Poll Question?",style: GoogleFonts.poppins(color: Color.fromRGBO(18,18,18,1),fontSize: 30),),
              SizedBox(height: 5,),
              Container(
                child: TextFormField(
                  controller: ques,
                  maxLines: 4,
                  onFieldSubmitted: (text) {
                    print(text);
                  },
                  decoration: InputDecoration(
                    hintText: "Ask a question",
                    hintStyle: GoogleFonts.poppins(),
                    border: InputBorder.none,
                    enabledBorder: OutlineInputBorder(
                      borderSide: BorderSide(
                        color: Color.fromRGBO(18,18,18,1)
                      ),
                    ),
                  ),
                ),
              ),
              SizedBox(height: 20,),
              Text("Option A?",style: GoogleFonts.poppins(color: Color.fromRGBO(18,18,18,1),fontSize: 25),),
              SizedBox(height: 5,),
              Container(
                child: TextFormField(
                  controller: a,
                  maxLines: 1,
                  onFieldSubmitted: (text) {
                    print(text);
                  },
                  decoration: InputDecoration(
                    hintText: "Enter Option A",
                    hintStyle: GoogleFonts.poppins(),
                    border: InputBorder.none,
                    enabledBorder: OutlineInputBorder(
                      borderSide: BorderSide(
                          color: Color.fromRGBO(18,18,18,1)
                      ),
                    ),
                  ),
                ),
              ),
              SizedBox(height: 20,),
              Text("Option B?",style: GoogleFonts.poppins(color: Color.fromRGBO(18,18,18,1),fontSize: 25),),
              SizedBox(height: 5,),
              Container(
                child: TextFormField(
                  controller: b,
                  maxLines: 1,
                  onFieldSubmitted: (text) {
                    print(text);
                  },
                  decoration: InputDecoration(
                    hintText: "Enter Option B",
                    hintStyle: GoogleFonts.poppins(),
                    border: InputBorder.none,
                    enabledBorder: OutlineInputBorder(
                      borderSide: BorderSide(
                          color: Color.fromRGBO(18,18,18,1)
                      ),
                    ),
                  ),
                ),
              ),
              SizedBox(height: 20,),
              Text("Option C?",style: GoogleFonts.poppins(color: Color.fromRGBO(18,18,18,1),fontSize: 25),),
              SizedBox(height: 5,),
              Container(
                child: TextFormField(
                  controller: c,
                  maxLines: 1,
                  onFieldSubmitted: (text) {
                    print(text);
                  },
                  decoration: InputDecoration(
                    hintText: "Enter Option C",
                    hintStyle: GoogleFonts.poppins(),
                    border: InputBorder.none,
                    enabledBorder: OutlineInputBorder(
                      borderSide: BorderSide(
                          color: Color.fromRGBO(18,18,18,1)
                      ),
                    ),
                  ),
                ),
              ),
              SizedBox(height: 20,),
              Text("Option D?",style: GoogleFonts.poppins(color: Color.fromRGBO(18,18,18,1),fontSize: 25),),
              SizedBox(height: 5,),
              Container(
                child: TextFormField(
                  controller: d,
                  maxLines: 1,
                  onFieldSubmitted: (text) {
                    print(text);
                  },
                  decoration: InputDecoration(
                    hintText: "Enter Option D",
                    hintStyle: GoogleFonts.poppins(),
                    border: InputBorder.none,
                    enabledBorder: OutlineInputBorder(
                      borderSide: BorderSide(
                          color: Color.fromRGBO(18,18,18,1)
                      ),
                    ),
                  ),
                ),
              ),
              SizedBox(height: 20,),
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Container(
                    decoration: BoxDecoration(
                      color: Color.fromRGBO(18,18,18,1),
                      borderRadius: BorderRadius.circular(4)
                    ),
                    child: MaterialButton(
                      onPressed: () async{
                        Map res=await addPoll();
                        if(res['id']!=null) {
                          Navigator.of(context).push(MaterialPageRoute(
                            builder: (context) =>PollAddSuccess(Result: res,)
                          ));
                        }
                        else {
                          Navigator.of(context).pop();
                        }
                      },
                      child: Text("Register Poll",style: GoogleFonts.poppins(fontSize: 16,color: Colors.white,fontWeight: FontWeight.w500),),
                    ),
                  )
                ],
              ),
              SizedBox(height: 10,),
            ],
          ),
        ),
      ),
    );
  }
}
