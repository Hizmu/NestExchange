// execute command - " mongosh < mongocollectionsinit.js "
use NestDB
db.account.drop()
db.createCollection("account",{
	validator:{
		$jsonSchema: {
			bsonType: "object",
			required: ["login","email","mobile","password","registrationdate","lastlogindate"],
			uniqueItems: true,
			properties: {
				login:{
					bsonType: "string",
					description: "login - It is required and it must be a string with length between 4 and 20",
					minimum: 4,
					maximum: 20,
				},
				email: {
					bsonType: "string",
					minimum: 6,
					maximum: 40,
					pattern: "[a-z0-9._%+!$&*=^|~#%{}/-]+@([a-z0-9-]+.){1,}([a-z]{2,22})",
					description: "email - It is required and it must be a string with length between 6 and 40 (regular expression pattern)"
				},
				mobile: {
					bsonType: "string",
					minimum: 9,
					maximum: 10,
					description: "mobile - It is required and it must be a string with length between 9 and 10"
				},
				password:{
					bsonType: "string",
					minimum: 8,
					maximum: 16,
					description: "password - It is required and it must be a string with length between 8 and 16"
				},
				registrationdate:{bsonType:"date",description:"It must be a date, is required"},
				lastlogindate:{bsonType:"date",description:"It must be a date, is required"}
			}
		}
	}
})
db.account.createIndex({login: 1, email:1,mobile:1},{unique:true})
/*
 * Test insert Account 
 *
 * db.account.insertOne({login:"test",
	email:"test@test.com",
	mobile:"123456789",
	password:"123456789",
	registrationdate: new ISODate(),
	lastlogindate: new ISODate()})*/
